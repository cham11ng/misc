
       WRITE (*, *) 'ENTER VALUE OF A B C'
       READ (*, *) a, b, c
       s = (a + b + c) / 2.0
       
       IF( a+b .LE. c .OR. b+c .LE. a .OR. c+a .LE. b)
           GOTO 2

       area= SQRT(s*(s-a)*(s-b)*(s-c))

       
       WRITE (*, *) 'Area OF Triangle= '
       WRITE (*, *) area
       GOTO 3

 2     WRITE(*, *) 'CAN''T SOLVE'
 
 3     STOP
       END
       
