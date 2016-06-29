;; Auto-generated. Do not edit!


(when (boundp 'commande_baxter::bool_state)
  (if (not (find-package "COMMANDE_BAXTER"))
    (make-package "COMMANDE_BAXTER"))
  (shadow 'bool_state (find-package "COMMANDE_BAXTER")))
(unless (find-package "COMMANDE_BAXTER::BOOL_STATE")
  (make-package "COMMANDE_BAXTER::BOOL_STATE"))
(unless (find-package "COMMANDE_BAXTER::BOOL_STATEREQUEST")
  (make-package "COMMANDE_BAXTER::BOOL_STATEREQUEST"))
(unless (find-package "COMMANDE_BAXTER::BOOL_STATERESPONSE")
  (make-package "COMMANDE_BAXTER::BOOL_STATERESPONSE"))

(in-package "ROS")





(defclass commande_baxter::bool_stateRequest
  :super ros::object
  :slots (_query ))

(defmethod commande_baxter::bool_stateRequest
  (:init
   (&key
    ((:query __query) nil)
    )
   (send-super :init)
   (setq _query __query)
   self)
  (:query
   (&optional __query)
   (if __query (setq _query __query)) _query)
  (:serialization-length
   ()
   (+
    ;; bool _query
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _query
       (if _query (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _query
     (setq _query (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass commande_baxter::bool_stateResponse
  :super ros::object
  :slots (_state ))

(defmethod commande_baxter::bool_stateResponse
  (:init
   (&key
    ((:state __state) nil)
    )
   (send-super :init)
   (setq _state __state)
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; bool _state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _state
       (if _state (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _state
     (setq _state (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass commande_baxter::bool_state
  :super ros::object
  :slots ())

(setf (get commande_baxter::bool_state :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande_baxter::bool_state :datatype-) "commande_baxter/bool_state")
(setf (get commande_baxter::bool_state :request) commande_baxter::bool_stateRequest)
(setf (get commande_baxter::bool_state :response) commande_baxter::bool_stateResponse)

(defmethod commande_baxter::bool_stateRequest
  (:response () (instance commande_baxter::bool_stateResponse :init)))

(setf (get commande_baxter::bool_stateRequest :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande_baxter::bool_stateRequest :datatype-) "commande_baxter/bool_stateRequest")
(setf (get commande_baxter::bool_stateRequest :definition-)
      "bool query
---
bool state

")

(setf (get commande_baxter::bool_stateResponse :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande_baxter::bool_stateResponse :datatype-) "commande_baxter/bool_stateResponse")
(setf (get commande_baxter::bool_stateResponse :definition-)
      "bool query
---
bool state

")



(provide :commande_baxter/bool_state "c7a88ab7a85f83bcb882571b8469aebb")


