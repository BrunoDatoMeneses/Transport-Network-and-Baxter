
(cl:in-package :asdf)

(defsystem "commande_baxter-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "bool_state" :depends-on ("_package_bool_state"))
    (:file "_package_bool_state" :depends-on ("_package"))
  ))