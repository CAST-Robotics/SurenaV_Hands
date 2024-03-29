#PARAMETERS TO CHANGE: ____________________________
N=800
urfdName="SURENA/S5_Mod.urdf"  #surenaFIXEDtoWorld.urdf
#urfdName="SURENA/surena4_contin.urdf" 
txtName="shakehands.txt"
RightArm=True
Plot=True
#__________________________________________________

from os import MFD_HUGE_64KB
import numpy as np
import pybullet as p
import time
import pybullet_data

#Reading inputs from the file
with open(txtName) as f:
    lines = f.readlines()
    
f.close()

M=np.zeros(N*7)
i=0
for number in lines:
    M[i]=float(number)
    i+=1

#_____________

def Reset():
    
    startPos = [0,0,0]
    startOrientation = p.getQuaternionFromEuler([0,0,0])
    p.resetSimulation()
    planeId = p.loadURDF("plane.urdf") 
    Sid=p.loadURDF(urfdName, useFixedBase=True)
    p.setGravity(0,0,-9.81)
    p.setTimeStep(1./200.)
    p.stepSimulation()

    return Sid,planeId

#_____________

physicsClient = p.connect(p.GUI) #,options="--opengl2"
p.setAdditionalSearchPath(pybullet_data.getDataPath()) #optionally

joints=list(range(14,21)) if RightArm else list(range(21,28)) 

feedback_theta=np.zeros([N,7])
feedback_thetaDot=np.zeros([N,7])
actions=np.zeros([N,7])

Vrate=1

#_____________
i=0
j=0
flag=True
Sid,planeId=Reset()
while flag:

    time.sleep((1./200.)/Vrate)

    p.setJointMotorControlArray(bodyUniqueId=Sid,
                                jointIndices=joints,
                                controlMode=p.POSITION_CONTROL,
                                targetPositions = M[j:j+7]
                                ) #forces=np.full((7,),10.)
    p.stepSimulation()
    
    actions[i]=M[j:j+7]
    JointStates=p.getJointStates(Sid,joints)
    for ii in range(7):
        feedback_theta[i][ii]=JointStates[ii][0] #theta
        feedback_thetaDot[i][ii]=JointStates[ii][1] #theta_dot

    
        
    j+=7
    i+=1
    if i==N:    
        print("_____ Press Y if you want to replay, N if you want to continue, a number if you want to change the rate _____")
        inp=input()
        try:
            Vrate = float(inp)
            Reset()
            i,j=0,0 
        except ValueError:
            if (inp=="Y" or inp=="y"):
                Reset()
                i,j,Vrate=0,0,1    
            else:
                flag=False
        
print("right_arm,right_hand,left arm,left hand",p.getLinkStates(Sid,[19,20,26,27]))
p.disconnect()


def cal_derivative(param):
    der=np.zeros((N,7))
    for i in range(1,N):
        for j in range(7):
            der[i][j]=(param[i][j]-param[i-1][j])*200.

    return der


def plot_actions(): 
    plt.figure()
    plt.plot(actions)
    plt.legend([1,2,3,4,5,6,7])
    plt.title("Actions")  

def plot_feedbacks():
    plt.figure()
    plt.plot(feedback_theta)
    plt.legend([1,2,3,4,5,6,7])
    plt.title("FeedBack Theta")

    plt.figure()
    plt.plot(feedback_thetaDot)
    plt.legend([1,2,3,4,5,6,7])
    plt.title("FeedBack Theta_Dot")

    plt.figure()
    plt.plot(accelerations)
    plt.legend([1,2,3,4,5,6,7])
    plt.title("Accelerations")

    plt.figure()
    plt.plot(jerks)
    plt.legend([1,2,3,4,5,6,7])
    plt.title("Jerks")


if Plot:
    import matplotlib.pyplot as plt
    accelerations=cal_derivative(feedback_thetaDot)
    jerks=cal_derivative(accelerations)
    plot_actions()
    plot_feedbacks()
    plt.show()

print("^_^")