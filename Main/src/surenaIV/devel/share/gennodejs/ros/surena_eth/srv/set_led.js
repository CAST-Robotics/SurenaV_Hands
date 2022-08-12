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

class set_ledRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.effect = null;
    }
    else {
      if (initObj.hasOwnProperty('effect')) {
        this.effect = initObj.effect
      }
      else {
        this.effect = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type set_ledRequest
    // Serialize message field [effect]
    bufferOffset = _serializer.int16(obj.effect, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type set_ledRequest
    let len;
    let data = new set_ledRequest(null);
    // Deserialize message field [effect]
    data.effect = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'surena_eth/set_ledRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd5b16c38fab6ec555795be0fbd20633f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 effect
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new set_ledRequest(null);
    if (msg.effect !== undefined) {
      resolved.effect = msg.effect;
    }
    else {
      resolved.effect = 0
    }

    return resolved;
    }
};

class set_ledResponse {
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
    // Serializes a message object of type set_ledResponse
    // Serialize message field [result]
    bufferOffset = _serializer.int16(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type set_ledResponse
    let len;
    let data = new set_ledResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'surena_eth/set_ledResponse';
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
    const resolved = new set_ledResponse(null);
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
  Request: set_ledRequest,
  Response: set_ledResponse,
  md5sum() { return 'e25c7994b68742a69959bfbdd1390188'; },
  datatype() { return 'surena_eth/set_led'; }
};
