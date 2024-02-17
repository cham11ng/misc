        PI = 22 / 7.0
        WRITE (*, *) 'Enter Radius and Height of Cylinder'
        READ (*, *) R, H
        
        BA = 2 * PI * R**2
        TSA = 2 * PI * R * (R+H)
        CSA = 2 * PI * R * H
        VO = PI * R**2 * H
        
        WRITE (*, *) 'Required Base Area ', BA
        WRITE (*, *) 'Total Surface Area', TSA
        WRITE (*, *) 'Curved Surface Area', CSA
        WRITE (*, *) 'Volume', VO
        pause
        stop
        end
