; Auto-generated. Do not edit!


(cl:in-package commande_baxter-srv)


;//! \htmlinclude bool_state-request.msg.html

(cl:defclass <bool_state-request> (roslisp-msg-protocol:ros-message)
  ((query
    :reader query
    :initarg :query
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass bool_state-request (<bool_state-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bool_state-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bool_state-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name commande_baxter-srv:<bool_state-request> is deprecated: use commande_baxter-srv:bool_state-request instead.")))

(cl:ensure-generic-function 'query-val :lambda-list '(m))
(cl:defmethod query-val ((m <bool_state-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader commande_baxter-srv:query-val is deprecated.  Use commande_baxter-srv:query instead.")
  (query m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bool_state-request>) ostream)
  "Serializes a message object of type '<bool_state-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'query) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bool_state-request>) istream)
  "Deserializes a message object of type '<bool_state-request>"
    (cl:setf (cl:slot-value msg 'query) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bool_state-request>)))
  "Returns string type for a service object of type '<bool_state-request>"
  "commande_baxter/bool_stateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bool_state-request)))
  "Returns string type for a service object of type 'bool_state-request"
  "commande_baxter/bool_stateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bool_state-request>)))
  "Returns md5sum for a message object of type '<bool_state-request>"
  "c7a88ab7a85f83bcb882571b8469aebb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bool_state-request)))
  "Returns md5sum for a message object of type 'bool_state-request"
  "c7a88ab7a85f83bcb882571b8469aebb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bool_state-request>)))
  "Returns full string definition for message of type '<bool_state-request>"
  (cl:format cl:nil "bool query~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bool_state-request)))
  "Returns full string definition for message of type 'bool_state-request"
  (cl:format cl:nil "bool query~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bool_state-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bool_state-request>))
  "Converts a ROS message object to a list"
  (cl:list 'bool_state-request
    (cl:cons ':query (query msg))
))
;//! \htmlinclude bool_state-response.msg.html

(cl:defclass <bool_state-response> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass bool_state-response (<bool_state-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bool_state-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bool_state-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name commande_baxter-srv:<bool_state-response> is deprecated: use commande_baxter-srv:bool_state-response instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <bool_state-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader commande_baxter-srv:state-val is deprecated.  Use commande_baxter-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bool_state-response>) ostream)
  "Serializes a message object of type '<bool_state-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'state) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bool_state-response>) istream)
  "Deserializes a message object of type '<bool_state-response>"
    (cl:setf (cl:slot-value msg 'state) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bool_state-response>)))
  "Returns string type for a service object of type '<bool_state-response>"
  "commande_baxter/bool_stateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bool_state-response)))
  "Returns string type for a service object of type 'bool_state-response"
  "commande_baxter/bool_stateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bool_state-response>)))
  "Returns md5sum for a message object of type '<bool_state-response>"
  "c7a88ab7a85f83bcb882571b8469aebb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bool_state-response)))
  "Returns md5sum for a message object of type 'bool_state-response"
  "c7a88ab7a85f83bcb882571b8469aebb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bool_state-response>)))
  "Returns full string definition for message of type '<bool_state-response>"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bool_state-response)))
  "Returns full string definition for message of type 'bool_state-response"
  (cl:format cl:nil "bool state~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bool_state-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bool_state-response>))
  "Converts a ROS message object to a list"
  (cl:list 'bool_state-response
    (cl:cons ':state (state msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'bool_state)))
  'bool_state-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'bool_state)))
  'bool_state-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bool_state)))
  "Returns string type for a service object of type '<bool_state>"
  "commande_baxter/bool_state")