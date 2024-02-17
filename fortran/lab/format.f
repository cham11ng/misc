       INTEGER ROLL
        REAL MARK
        CHARACTER NAME * 20
        WRITE(*, *) 'ENTER NAME ROLL AND MARK'
        READ (*, *) NAME, ROLL, MARK
        WRITE (*, 10) NAME, ROLL, MARK
10      FORMAT (1X, 'NAME=', T20, A, / 'ROLL=', T20, I3, / 'MARK=', T20,    !i3 w-dth
     $  F6.2)
        goto 12
12      STOP
        END
   
        
