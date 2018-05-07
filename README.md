# Sacrifice Management System
Consider a mosque that facilitates people to offer animal sacrifices at Eid-ul-Azha. You need to develop an information system to help the administration track animals, customers -- the persons offering sacrifices, the money involved, and the meat. Following are the details:

The mosque purchases several animals a few days before the Eid, and displays them in open to the public. Each animal is tagged with an identification number, and the day of sacrifice: first, second or third -- The activity of sacrifice continues for three days of the Eid, and the administration schedules sacrifices of the animals around these three days.


People visit animals, selects animal(s), and then ask one of the several front desk officers for booking. If the animal (or its share) is available the officer records the booking, otherwise he asks the visitor to select some other animal. The visitor may ask the officer to give a (short) list of the available animals. The list, for example, may tell identification numbers of any five available cows due on the second day of Eid.


Besides the selected animal(s), the mosque records personal information of the customer such as her name, address and phone number, and provides a booking receipt to the customer. The receipt contains the name of the officer involved in the transaction.


Interestingly, some animals are shareable such as cow and camel; others are not, for example sheep. Each shareable animal has seven shares, and each share can be owned by a different person. A single person however may purchase more than one shares, and may even opt to sacrifice more than one animals!


After the sacrifice, the meat is packed and labeled for identification. When the customer arrives to take the packets, the officer asks for her signatures in a manual register, and records the delivery in the computer system.


The system has two kinds of users: front desk officers, and an administrator. The administrator can access all the features of the system, and can add/remove user accounts for the officers. The officers cannot create or edit their accounts, and cannot add/remove animals. However, they can change their passwords.