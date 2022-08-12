// Auto-generated. Do not edit!

// (in-package surena_eth.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class homeRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.nodeID = null;
    }
    else {
      if (initObj.hasOwnProperty('nodeID')) {
        this.nodeID = initObj.nodeID
      }
      else {
        this.nodeID = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type homeRequest
    // Serialize message field [nodeID]
    bufferOffset = _serializer.int16(obj.nodeID, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type homeRequest
    let len;
    let data = new homeRequest(null);
    // Deserialize message field [nodeID]
    data.nodeID = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'surena_eth/homeRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ab70d03352862bd3e7f20efd8fa5cb9d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 nodeID
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new homeRequest(null);
    if (msg.nodeID !== undefined) {
      resolved.nodeID = msg.nodeID;
    }
    else {
      resolved.nodeID = 0
    }

    return resolved;
    }
};

class homeResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type homeResponse
    // Serialize message field [result]
    bufferOffset = _serializer.int16(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type homeResponse
    let len;
    let data = new homeResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'surena_eth/homeResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e2c2de4947863e4feccd94cb02ed28ea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 result
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new homeResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: homeRequest,
  Response: homeResponse,
  md5sum() { return '9d17c7a086f295f3ddeb8ac344bfc6ca'; },
  datatype() { return 'surena_eth/home'; }
};
