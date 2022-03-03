========================================
#                                      #
#              2021 - 2022             #
#        Attiki Odos Simulation        #
#                                      #
========================================
#                                      #
#           Παρασκευάς Μπόκορης        #
#           Α.Μ.  115201900126         #
#                                      #
#           Δαμιανάκης Δαμιανός        #
#           Α.Μ. 1115201800106         #
#                                      #
========================================

2)Εντολή μεταγλώττισης του προγράμματος

    make

    ή
  
    Για να ξανα κανετε μεταγλωττιση θα πρεπει να πρωτα να κανετε "make clean" και επειτα "make"

========================================

3)Εντολή εκτέλεσης του προγράμματος

  make run

========================================

4)Σχεδιαστικές επιλογές - Περιγραφή κώδικα

Το Αττικη Οδος Simulation ειναι ενα προγραμμα οπου σας
παρουσιαζει την λειτουργικοτητα της ατικκης οδου οπου 
περιεχει μεσα αυτοκινητα. 
Τα αυτοκινητα οπου βρισκονται μεσα στον αυτοκινητοδρομο περνανε 
απο κομβους και διοδια ωστε να φτασουν στην εξοδο που επιθυμει
το καθε αυτοκινητο.

Εκτελωντας το Αττικη Οδος Simulation θα εισαχθουν οι παραμετοι
που δινονται απο το Makefile.
Αυτοι οι παραμετροι ειναι οι εξης: N = ο αριθμος κυκλου των προσομοιωσεων, nSegs = ειναι συνολικος 
αριθμος τμηματων, Κ = ο μεγιστος αριθμος οχηματων ανα τμημα, Percent = το ποσοστο οχηματων που θα εχει
το καθε τμημα.

Κατα την εκτελεση του προγραμματος θα σας εμφανιζει αντιστοιχα μηνυματα για την δημιουργια των
αντικειμενων (πχ. τα τμηματα) τελος σας εμφανιζει καθε ποτε κανει ειναι ετοιμα τα αυτοκινητα 
να πανε στο επομενο τμημα του αυτοκινητοδρομου.

Η operate ειναι υπευθυνη για την διακηνηση το οχηματων μεσα στον αυτοκινητοδρομο.

Η Enter ειναι υπευθυνη για την εισαγωγη των αυτοκινητων στα διοδια και στα τμηματα.

Η Exit ειναι υπευθυνη για την εξαγωγη των αυτοκινητων απο τα διοδια και απο τα τμηματα αλλα και απο 
τον αυτοκινητοδρομο.

Η δομη του προγραμματος έχει ως εξης: όλα τα .cpp αρχεία
είναι οργανωμενα σε ξεχωριστό φάκελο modules και τα headers files 
σε ξεχωριστό φάκελο headers. Μέσα σε αυτούς τους φακέλους υπάρχουν 
οι ζητούμενες κλάσεις. Έξω από τους φακέλους υπάρχει η συνάρτηση 
λεγεται main.cpp μαζί με το main.h στο οποίο βρίσκονται 
οι βασικές βιβλιοθήκες που χρησιμοποιούμε στο project.
Το πρόγραμμα είναι χωρισμένο στις εξής κλάσεις: segment, 
highway, vehicle, toll και entrance.Πέρα από αυτά έχουμε φτιάξει και αρχείο makefile.


