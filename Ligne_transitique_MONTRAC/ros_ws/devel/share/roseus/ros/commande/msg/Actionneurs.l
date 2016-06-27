;; Auto-generated. Do not edit!


(when (boundp 'commande::Actionneurs)
  (if (not (find-package "COMMANDE"))
    (make-package "COMMANDE"))
  (shadow 'Actionneurs (find-package "COMMANDE")))
(unless (find-package "COMMANDE::ACTIONNEURS")
  (make-package "COMMANDE::ACTIONNEURS"))

(in-package "ROS")
;;//! \htmlinclude Actionneurs.msg.html


(defclass commande::Actionneurs
  :super ros::object
  :slots (_actionneurs ))

(defmethod commande::Actionneurs
  (:init
   (&key
    ((:actionneurs __actionneurs) 0)
    )
   (send-super :init)
   (setq _actionneurs (round __actionneurs))
   self)
  (:actionneurs
   (&optional __actionneurs)
   (if __actionneurs (setq _actionneurs __actionneurs)) _actionneurs)
  (:serialization-length
   ()
   (+
    ;; int64 _actionneurs
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _actionneurs
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _actionneurs (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _actionneurs) (= (length (_actionneurs . bv)) 2)) ;; bignum
              (write-long (ash (elt (_actionneurs . bv) 0) 0) s)
              (write-long (ash (elt (_actionneurs . bv) 1) -1) s))
             ((and (class _actionneurs) (= (length (_actionneurs . bv)) 1)) ;; big1
              (write-long (elt (_actionneurs . bv) 0) s)
              (write-long (if (>= _actionneurs 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _actionneurs s)(write-long (if (>= _actionneurs 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _actionneurs
#+(or :alpha :irix6 :x86_64)
      (setf _actionneurs (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _actionneurs (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get commande::Actionneurs :md5sum-) "1a79d0b13aebfb5d0450ddf675b8fc68")
(setf (get commande::Actionneurs :datatype-) "commande/Actionneurs")
(setf (get commande::Actionneurs :definition-)
      "int64 actionneurs



")



(provide :commande/Actionneurs "1a79d0b13aebfb5d0450ddf675b8fc68")


