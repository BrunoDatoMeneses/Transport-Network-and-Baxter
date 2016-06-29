;; Auto-generated. Do not edit!


(when (boundp 'commande::Capteurs)
  (if (not (find-package "COMMANDE"))
    (make-package "COMMANDE"))
  (shadow 'Capteurs (find-package "COMMANDE")))
(unless (find-package "COMMANDE::CAPTEURS")
  (make-package "COMMANDE::CAPTEURS"))

(in-package "ROS")
;;//! \htmlinclude Capteurs.msg.html


(defclass commande::Capteurs
  :super ros::object
  :slots (_capteurs ))

(defmethod commande::Capteurs
  (:init
   (&key
    ((:capteurs __capteurs) 0)
    )
   (send-super :init)
   (setq _capteurs (round __capteurs))
   self)
  (:capteurs
   (&optional __capteurs)
   (if __capteurs (setq _capteurs __capteurs)) _capteurs)
  (:serialization-length
   ()
   (+
    ;; int64 _capteurs
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _capteurs
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _capteurs (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _capteurs) (= (length (_capteurs . bv)) 2)) ;; bignum
              (write-long (ash (elt (_capteurs . bv) 0) 0) s)
              (write-long (ash (elt (_capteurs . bv) 1) -1) s))
             ((and (class _capteurs) (= (length (_capteurs . bv)) 1)) ;; big1
              (write-long (elt (_capteurs . bv) 0) s)
              (write-long (if (>= _capteurs 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _capteurs s)(write-long (if (>= _capteurs 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _capteurs
#+(or :alpha :irix6 :x86_64)
      (setf _capteurs (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _capteurs (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get commande::Capteurs :md5sum-) "bf794154bbba9db270fca7e0cc669d41")
(setf (get commande::Capteurs :datatype-) "commande/Capteurs")
(setf (get commande::Capteurs :definition-)
      "int64 capteurs


")



(provide :commande/Capteurs "bf794154bbba9db270fca7e0cc669d41")


