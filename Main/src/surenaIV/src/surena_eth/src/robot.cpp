#include "robot.h"
//#include"QsLog/QsLogDisableForThisFile.h"
//=================================================================================================
Robot::Robot(QObject *parent, int argc, char **argv)
{
qDebug()<<"?BGVYH^VDXS??????????????????????????????????";
    _rosNode=new QNode(argc,argv);
    if(!_rosNode->Init())
    {
        QLOG_FATAL()<<"Ros node init error please check ros master!";
        exit(0);
    }
    QLOG_TRACE()<<"Ros node successfuly created";
    _rosNode->RobotStatus="Initialize";
    //if(Epos4.Init(2)==OK){qDebug()<<"ok";return;}
    //   connect(&_statusCheckTimer,SIGNAL(timeout()),this,SLOT(StatusCheck()));

    //_statusCheckTimer.start(1000);
    pos=0;
    connect(_rosNode,SIGNAL(rosShutdown()),this,SLOT(CleanAndExit()));
    connect(_rosNode,SIGNAL(NewjointDataReceived()),this,SLOT(NewjointDataReceived()));
    connect(_rosNode,SIGNAL(SetActiveCSP(int)),this,SLOT(ActiveCSP(int)));
    connect(_rosNode,SIGNAL(DoResetAllNodes(int)),this,SLOT(ResetAllNodes(int)));
    connect(_rosNode,SIGNAL(DoResetLegs()),this,SLOT(ResetLegs()));

    connect(_rosNode,SIGNAL(DoResetHands()),this,SLOT(ResetHands()));
    connect(_rosNode,SIGNAL(UpdateAllPositions()),this,SLOT(ReadAllInitialPositions()));
    connect(_rosNode,SIGNAL(DoActivateHands()),this,SLOT(ActivateHands()));
    connect(_rosNode,SIGNAL(DoActivateLegs()),this,SLOT(ActivateLegs()));
    connect(_rosNode,SIGNAL(DoReadError()),this,SLOT(ReadErrors()));
    connect(_rosNode,SIGNAL(SetHome(int)),this,SLOT(Home(int)));
    connect(_rosNode,SIGNAL(DoSetLed(int)),this,SLOT(SetLed(int)));
    connect(&Epos4,SIGNAL(FeedBackReceived(QList<int16_t>,QList<int32_t>,QList<int32_t>,QList<uint16_t>,QList<float>)),this,SLOT(FeedBackReceived(QList<int16_t>,QList<int32_t>,QList<int32_t>,QList<uint16_t>,QList<float>)));
    connect(&_initialTimer,SIGNAL(timeout()),this,SLOT(Initialize()));


    _initialTimer.start(2000);

    QLOG_TRACE()<<"Start initialize...";

}
//=================================================================================================
void Robot::Initialize()
{
    //qDebug()<<"z check...";
    //if(!Epos4.CheckZynq())return;
    //qDebug()<<"init...";
    //if(Epos4.Init(2)!=OK)
    //    return;
    //QElapsedTimer t;
    //t.start();
    //int32_t result=0;
    //QList<int32_t> alldata;
    //for(int i=0;i<1;i++){
    //Epos4.ReadRegister(0x1000,0,1,i,result,20,1);
    //alldata.append(result);
    //}

    //for(int i=0;i<alldata.length();i++)
    //qDebug()<<QString::number( alldata[i],16);
    if(!ReadAllInitialPositions())
    {
        QLOG_ERROR()<<"mybe robot power is down";
        return;

    }
//ReadAllInitialPositions();

    ////Epos4.ReadAllRegisters(0x60e4,1,1,results,10);
    //qDebug()<<"------------------------------start";
    //int32_t result;
    //result=Epos4.ReadRegister(0x1000,0,1,2,10,1);
    //(int index,int subIndex,int canID, int devID,int timeout,int trycount)
    //for(int i=0;i<4;i++){
    //result=   Epos4.ReadRegister(0x60e4,2,i+1,12,10,1);
    //qDebug()<<"get val="<<QString::number( result,16)<<result;
    //result=   Epos4.ReadRegister(0x60e4,2,i+1,13,10,1);
    //qDebug()<<"get val="<<QString::number( result,16)<<result;

    //}
    //qDebug()<<"get val="<<QString::number( result,16)<<result;
    //QList<int32_t> results;
    //Epos4.ReadAllRegisters(0x1000,0,1,results,10); //this function socks
    //qDebug()<<"------------------------------end";
    //if(results.count()>2)qDebug()<<QString::number( results[2],16);
    //return;



    //qDebug()<<"foot init...OK";
    //if(Epos4.HandsInit(2)!=OK)
    //{
    // return;
    //}


    //if(! ReadAllInitialPositions())
    //{return; }


    //_initialTimer.stop();

    //   Epos4.ActivePPMPDO(13,1);
    //   Epos4.ActivePPMPDO(13,2);
    //   Epos4.ActivePPMPDO(13,3);
    //   Epos4.ActivePPMPDO(13,4);

    //Epos4.ActivePPMPDO(12,1);
    //Epos4.ActivePPMPDO(12,2);
    //Epos4.ActivePPMPDO(12,3);
    //Epos4.ActivePPMPDO(12,4);

    qDebug()<<"hands init...OK";
    _initialTimer.stop();
    connect(&timer,SIGNAL(timeout()),this,SLOT(Timeout()));
    Initialized=true;
    //Epos4.ActiveJoint(2);
    //Epos4.ActiveAllHands();
    //Epos4.ActiveCSP(255);
    //Epos4.StartFeedBack();
    //timer.start(5);

    _rosNode->RobotStatus="Ready";
    QLOG_TRACE()<<"initialize Completed";

}
//=================================================================================================
bool Robot::ReadAllInitialPositions()
{

    try{

    QLOG_TRACE()<<"Read inc and absoulute encoders";
         qDebug()<<"upper body=====================================";
    int32_t result;
    //result=Epos4.ReadRegister(0x1000,0,1,2,10,1);
    //(int index,int subIndex,int canID, int devID,int timeout,int trycount)
    for(int i=0;i<4;i++){
        result=   Epos4.ReadRegister(0x60e4,2,i+1,12,10,1);
             qDebug()<<"abs "<<i+12+1<<"=" << result;
        CurrentAbsPositions[12+i]=result;
        _rosNode->ActualPositions[i+12+1]=result;
        result=   Epos4.ReadRegister(0x6064,0,i+1,12,10,1);
             qDebug()<<"inc "<<i+12+1<<"=" << result;
        CurrentIncPositions[12+i]=result;
        _rosNode->IncPositions[i+12+1]=result;
        //qDebug()<<"get val="<<QString::number( result,16)<<result;
        result=   Epos4.ReadRegister(0x60e4,2,i+1,13,10,1);//pos act
             qDebug()<<"abs "<<i+20+1<<"=" << result;
        CurrentAbsPositions[20+i]=result;
        _rosNode->ActualPositions[i+20+1]=result;
        result=   Epos4.ReadRegister(0x6064,0,i+1,13,10,1);
             qDebug()<<"inc "<<i+20+1<<"=" << result;
        CurrentIncPositions[20+i]=result;
        _rosNode->IncPositions[i+20+1]=result;
        // qDebug()<<"get val="<<QString::number( result,16)<<result;

    }
     qDebug()<<"lower body=====================================";
    /////////////////// end hands
    int numberOfSuccess=0;
    for(int i=0;i<12;i++){
        int32_t result=0;


        result=Epos4.ReadRegister(0x60e4,1,1,i,10,3);
        //{
        CurrentIncPositions[i]=result;
        //  positionInc.append(result);
        numberOfSuccess++;
        qDebug()<<"inc "<<i<<"=" << result;
        _rosNode->IncPositions[i+1]=(CurrentIncPositions[i]);

    }
    //////////////////////
    for(int i=0;i<12;i++){
        int32_t result=0;
        // if(Epos4.ReadRegister(0x60e4,2,1,i,10,3)==OK)
        //{
        result=Epos4.ReadRegister(0x60e4,2,1,i,10,3);
        CurrentAbsPositions[i]=result;
        _rosNode->ActualPositions[i+1]=(CurrentAbsPositions[i]-offset[i])*ratio[i]*2*M_PI/8192;
        //  positionInc.append(result);
        numberOfSuccess++;
        qDebug()<<"ABS "<<i<<"=" << result;
        //(int index,int subIndex,int canID, int devID,int timeout,int trycount)
    }


    result=Epos4.ReadRegister(0x60e4,2,1,14,10,3);
    _rosNode->ActualPositions[29]=(result-offset[28])*ratio[28]*2*M_PI/8192;
   CurrentAbsPositions[28]=result;
   qDebug()<<"ABS waist abs"<<"=" << result;
   result=Epos4.ReadRegister(0x60e4,1,1,14,10,3);
   _rosNode->IncPositions[29]=result;
  CurrentIncPositions[28]=result;

   qDebug()<<"ABS waist inc"<<"=" << result;

    return true;
    }
    catch(const std::runtime_error e)
    {
QLOG_ERROR()<<e.what();
return false;
    }

}
//=================================================================================================
void Robot::WaitMs(int ms)
{
    QEventLoop q;
    QTimer tT;
    tT.setSingleShot(true);
    connect(&tT, SIGNAL(timeout()), &q, SLOT(quit()));
    tT.start(ms); // 5s timeout
    q.exec();
    if(tT.isActive()){
        // download complete
        tT.stop();
    } else {

    }
}
//=================================================================================================
void Robot::StatusCheck()
{
    qDebug()<<"init :"<<Initialized;
}
//=================================================================================================
void Robot::NewjointDataReceived()
{
    // qDebug()<<"get new data..."<<_rosNode->JointsData.data.at(20);
    QList<int> _motorPosition;
    int len=_rosNode->JointsData.data.size() ;

    for(int i=0; i<len ; i++)
    {
        _motorPosition.append(_rosNode->JointsData.data.at(i));
    }
    for(int i=0; i<34-len ; i++)
        _motorPosition.append(0);



    // motor offset dynamixel
    _motorPosition[24]+=(3000-50);
    _motorPosition[25]+=1650;
    _motorPosition[26]+=2150;
    _motorPosition[16]+=2500;//2450;
    _motorPosition[17]+=1550;
    _motorPosition[18]+=1850;

    _motorPosition[29]+=2470;
    _motorPosition[30]+=3080;
    _motorPosition[31]+=2048;
    _motorPosition[32]+=2051;

    Epos4.SetAllPositionCST(_motorPosition);
}
//=================================================================================================
void  Robot::FeedBackReceived(QList<int16_t> ft, QList<int32_t> positions,QList<int32_t> positionsInc,QList<uint16_t> bump_sensor_list,QList<float> imu_data_list)
{
    for(int i=0;i<12;i++){
        CurrentAbsPositions[i]=positions[i];
        CurrentIncPositions[i]=positionsInc[i];
        _rosNode->ActualPositions[i+1]=(positions[i]-offset[i])*ratio[i]*2*M_PI/8192;
        _rosNode->IncPositions[i+1]=positionsInc[i];  //  _rosNode->ActualJointState.position.push_back( _rosNode->ActualPositions[i+1]);
    }
    _rosNode->ActualPositions[29]=(positions[14]-offset[13])*ratio[13]*2*M_PI/8192;
    _rosNode->IncPositions[29]=positionsInc[14];
    CurrentIncPositions[28]=positionsInc[14];
    CurrentAbsPositions[28]=positions[14];
    if(bump_sensor_list.count()==8)
        for(int i=0;i<8;i++){
            _rosNode->BumpSensor[i]= bump_sensor_list[i];
        }
    _rosNode->imuSesnsorMsg=Epos4.IMU;
    _rosNode->RightFtSensorMessage=Epos4.ForceTorqSensorRight;
    _rosNode->LeftFtSensorMessage=Epos4.ForceTorqSensorLeft;

}
//=================================================================================================
void Robot::ActiveCSP(int id)
{
    //ReadAllInitialPositions();
    ////////////hand test
    _rosNode->RobotStatus="Motor Activating";
    qDebug()<<"active csp slot..."<<id;
    _rosNode->teststr="OK";
    timer.stop();

    //    if(id==255){
    //    QThread::msleep(5);
    //    Epos4.ActiveAllCSP();
    //    QThread::msleep(5);
    //    //Epos4.ActiveHand();
    //    }
    //    else
    //    {
    Epos4.ActiveJoint(id,true);
    //  }


    Epos4.ActiveWaist(true);
    _rosNode->OperationCompleted(0);
    _rosNode->RobotStatus="Ready";
}
//=================================================================================================
void Robot::ReadErrors()
{
    int32_t result=0;
    QString errorstr="";
    for(int i=0;i<12;i++){

        errorstr+= "M"+QString::number(i)+"->"+ Epos4.ReadCurrentError(1,i)+" ";

    }
    //qDebug()<<errorstr;
    _rosNode->RobotStatus=errorstr;
    _rosNode->OperationCompleted(0); //all good

}
//=================================================================================================
void Robot::ResetHands(void)
{
    try{
        qDebug()<<"Reset hands...";
        //12 15
        //20 //23
        for(int i=0;i<4;i++){
            Epos4.ResetNode(12);
            Epos4.ResetNode(13);

        }
        //for(int i=20;i<24;i++)
          //  Epos4.ResetNode(i);

        _rosNode->OperationCompleted(0);
        _rosNode->RobotStatus="Ready";
        qDebug()<<"operation completed!";
    }
    catch(const std::runtime_error e)
    {
        _rosNode->OperationCompleted(-1);
        //  timer.start(5);
        _rosNode->RobotStatus="Ready";
    }
}
//=================================================================================================

void Robot::ActivateHands(void)
{

    _rosNode->RobotStatus="Hand Motor Activating";
    qDebug()<<"activating hands";
    _rosNode->teststr="OK";
    timer.stop();
    Epos4.ActiveAllHands(true);
    _rosNode->OperationCompleted(0);
    _rosNode->RobotStatus="Ready";

}
//=================================================================================================

void Robot::ActivateLegs(void)
{

    _rosNode->RobotStatus="Lesg Motor Activating";
    qDebug()<<"activating Legs";
    _rosNode->teststr="OK";
    timer.stop();
    Epos4.ActiveLegs();
    qDebug()<<"activating Legs ok";
    _rosNode->OperationCompleted(0);
    _rosNode->RobotStatus="Ready";


}

//=================================================================================================
void Robot::ResetAllNodes(int id)
{
    try{
        _hommingTimer.stop();
        _rosNode->RobotStatus="Reseting Nodes";
        qDebug()<<"Reset all slot...";
        _rosNode->teststr="OK";
        Epos4.ResetNode(id);
        _rosNode->OperationCompleted(0);
        //  timer.start(5);
        _rosNode->RobotStatus="Ready";
        // Epos4.StartFeedBack();
    }
    catch(const std::runtime_error e)
    {
        _rosNode->OperationCompleted(-1);
        //  timer.start(5);
        _rosNode->RobotStatus="Ready";
    }
}
//=================================================================================================

void Robot::ResetLegs()
{
    try{
        _hommingTimer.stop();
        _rosNode->RobotStatus="Reseting Legs";
        qDebug()<<"Reset Legs...";
        _rosNode->teststr="OK";
        for(int i=0;i<12;i++)
        Epos4.ResetNode(i);
        _rosNode->OperationCompleted(0);
        _rosNode->RobotStatus="Ready";

    }
    catch(const std::runtime_error e)
    {
        _rosNode->OperationCompleted(-1);
        _rosNode->RobotStatus="Ready";
    }
}
//=================================================================================================
void Robot::SetLed(int id)
{

//Epos4.Led=id;
 Epos4.SetLed(id);
  _rosNode->OperationCompleted(0);
}

//=================================================================================================
void Robot::Home(int id)
{
    _rosNode->RobotStatus="Homming";
    QLOG_DEBUG()<<"start home";

    if(! ReadAllInitialPositions())
    {
        QLOG_ERROR()<<"Home error ->read positions error";
        _rosNode->OperationCompleted(-1);
        return;
    }
    _motorPosition.clear();
    for(int ii=0; ii<34 ; ii++)
    {
        _motorPosition.append( CurrentIncPositions[ii]);
    }




HomeTime=0;
//    currentHomeIndex=12;
    currentHomeIndex=0;
    homeLoopNumber=0;
    timer.stop();
    //void PIDController::Init(double dt, double max, double min, double Kp, double Kd, double Ki)
    pid.Init(5,10,-10,1.5,0,0.0);
    _hommingTimer.disconnect();
    connect(&_hommingTimer,SIGNAL(timeout()),this,SLOT(HommingLoop()));
   // Epos4.ActiveCSP(255);
    Epos4.ActiveAllHands(true);
Epos4.ActiveLegs();
Epos4.ActiveWaist();


    _hommingTimer.start(5);
    _rosNode->RobotStatus="Ready";
}
//=================================================================================================
void Robot::Timeout()
{
    QList<int> _motorPosition;
    // qDebug()<<"Tick";
    if(dir)pos+=1;
    else pos-=1;
    if(pos>300){dir=!dir;}
    if(pos<-300){dir=!dir;}
    //qDebug()<<pos;
    //_motorPosition.clear();
    for(int ii=0; ii<28 ; ii++)
    {
        _motorPosition.append( pos);
    }
    Epos4.SetAllPositionCST(_motorPosition);
}
double Robot::Move2Pose(double max,double t_local,double t_start ,double t_end){
    double t_move=t_end-t_start;
    double c3=(10*max)/pow(t_move,3);
    double c4=-(15*max)/pow(t_move,4);
    double c5=(6*max)/pow(t_move,5);
    double theta=0;
    if(t_local<t_start){theta=0;}
    else if (t_local<t_end){theta=c3*pow(t_local-t_start,3)+c4*pow(t_local-t_start,4)+c5*pow(t_local-t_start,5);}
    else{theta=max;}
    return theta;
}
//=================================================================================================
//void Robot::HommingLoop()
//{
//    //right hand

//    if(HomeTime5){
//        _motorPosition[12]=-10*120/60*(Move2Pose(offset[12]-CurrentAbsPositions[12],HomeTime,0,5))*360/8192*1;
//        _motorPosition[13]=10*120/60*(Move2Pose(offset[13]-CurrentAbsPositions[13],HomeTime,0,5))*360/8192*1;
//        _motorPosition[14]=-7*100/60*(-Move2Pose(offset[14]-CurrentAbsPositions[14],HomeTime,0,5))*360/8192*1;
//        _motorPosition[15]=7*100/60*(Move2Pose(offset[15]-CurrentAbsPositions[15],HomeTime,0,5))*360/8192;
//        _motorPosition[20]=10*120/60*(Move2Pose(offset[20]-CurrentAbsPositions[20],HomeTime,0,5))*360/8192*1;
//        _motorPosition[21]=10*120/60*(Move2Pose(offset[21]-CurrentAbsPositions[21],HomeTime,0,5))*360/8192*1;
//        _motorPosition[22]=-7*100/60*(-Move2Pose(offset[22]-CurrentAbsPositions[22],HomeTime,0,5))*360/8192*1;
//        _motorPosition[23]=-7*100/60*(-Move2Pose(offset[23]-CurrentAbsPositions[23],HomeTime,0,5))*360/8192*0;

//        Epos4.SetAllPositionCST(_motorPosition);
//        HomeTime+=0.005;


//if(HomeTime>=5){
//    qDebug()<<"hand homming finished!";
//                _hommingTimer.stop();
//    _rosNode->OperationCompleted(0);
//}
//}


void Robot::HommingLoop()
{
    int j=0;
    double max=15.0;
    //double kp=2000*2*M_PI/8192;//230400/2/3.14/2;
    double kp=1500*2*M_PI/8192;//230400/2/3.14/2;
//currentHomeIndex=12;
    j=HomeOrder[currentHomeIndex];

    if(abs((offset[j]-CurrentAbsPositions[j])*kp*Direction[j])<=max)
    {_motorPosition[j]+= ((offset[j]-CurrentAbsPositions[j]))*kp*Direction[j];}
    if(((offset[j]-CurrentAbsPositions[j])*kp*Direction[j])>max)
    {_motorPosition[j]+=(max);}
    if(((offset[j]-CurrentAbsPositions[j])*kp*Direction[j])<-max)
    {_motorPosition[j]-=(max);}

   // qDebug()<<"offset"<<offset[j]<<"position["<<j<<"]="<<CurrentAbsPositions[j]<<"command"<<_motorPosition[j];
    //// here we receive home
    if(offset[j]-CurrentAbsPositions[j]==0){

        currentHomeIndex++;

    }
    //  qDebug()<<"offset";



    if(currentHomeIndex>12&&HomeTime>5){
      //  currentHomeIndex=0;

//        for(int kk=0;kk<=12;kk++){
//            if(offset[kk]-CurrentAbsPositions[kk]>2 ||offset[kk]-CurrentAbsPositions[kk]<-2){

//                currentHomeIndex=0;

//            }

//        }

//        if(currentHomeIndex>0){
            qDebug()<<"Home Finished!";
            _hommingTimer.stop();
            _rosNode->OperationCompleted(0);
//        }



    }



//    // motor offset dynamixel
//    _motorPosition[24]+=3000;
//    _motorPosition[25]+=1650;
//    _motorPosition[26]+=2150;
//    _motorPosition[16]+=2500;//2450;
//    _motorPosition[17]+=1550;
//    _motorPosition[18]+=1850;

//    _motorPosition[29]+=2470;
//    _motorPosition[30]+=3080;
//    _motorPosition[31]+=2048;
//    _motorPosition[32]+=2051;
        if(HomeTime<5){
            _motorPosition[16]=2500;
            _motorPosition[17]=1550;
            _motorPosition[18]=1850;
            _motorPosition[24]=3000-50;
            _motorPosition[25]=1650;
            _motorPosition[26]=2150;
            _motorPosition[19]=_motorPosition[27]=9;
            _motorPosition[29]=2470;
            _motorPosition[30]=3080+int(Move2Pose(200,HomeTime,0,2)-Move2Pose(200,HomeTime,2,4));
            _motorPosition[31]=2048;
            _motorPosition[32]=2051;


            _motorPosition[12]=CurrentIncPositions[12]-int(10*120/60*(Move2Pose(offset[12]-CurrentAbsPositions[12],HomeTime,0,5))*360/8192*1);
            _motorPosition[13]=CurrentIncPositions[13]+int(10*120/60*(Move2Pose(offset[13]-CurrentAbsPositions[13],HomeTime,0,5))*360/8192*1);
            _motorPosition[14]=CurrentIncPositions[14]-int(7*100/60*(-Move2Pose(offset[14]-CurrentAbsPositions[14],HomeTime,0,5))*360/8192*1.065);
            _motorPosition[15]=CurrentIncPositions[15]+int(7*100/60*(Move2Pose(offset[15]-CurrentAbsPositions[15],HomeTime,0,5))*360/8192*1.083);
            _motorPosition[20]=CurrentIncPositions[20]+int(10*120/60*(Move2Pose(offset[20]-CurrentAbsPositions[20],HomeTime,0,5))*360/8192*1);
            _motorPosition[21]=CurrentIncPositions[21]+int(10*120/60*(Move2Pose(offset[21]-CurrentAbsPositions[21],HomeTime,0,5))*360/8192*1);
            _motorPosition[22]=CurrentIncPositions[22]-int(7*100/60*(-Move2Pose(offset[22]-CurrentAbsPositions[22],HomeTime,0,5))*360/8192*1.065);
            _motorPosition[23]=CurrentIncPositions[23]-int(7*100/60*(-Move2Pose(offset[23]-CurrentAbsPositions[23],HomeTime,0,5))*360/8192*1.083); //??

//if(fmod(HomeTime,.1)<.005){
//    qDebug()<<HomeTime;


//}
            _rosNode->IncPositions[13]=_motorPosition[12];
            _rosNode->IncPositions[14]=_motorPosition[13];
            _rosNode->IncPositions[15]=_motorPosition[14];
            _rosNode->IncPositions[16]=_motorPosition[15];
            _rosNode->IncPositions[21]=_motorPosition[20];
            _rosNode->IncPositions[22]=_motorPosition[21];
            _rosNode->IncPositions[23]=_motorPosition[22];
            _rosNode->IncPositions[24]=_motorPosition[23];
}


    Epos4.SetAllPositionCST(_motorPosition);
     HomeTime+=0.005;
    //qDebug()<<"addad"<<_motorPosition.count();

}

//=================================================================================================
void Robot::CleanAndExit()
{

    _hommingTimer.stop();
    _initialTimer.stop();
    timer.stop();
    //Epos4.~Epos();
    QLOG_DEBUG()<<"Clean and exit\n";
    WaitMs(2000);
    exit(0);

}
//=================================================================================================
