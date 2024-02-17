        write (*, *) 'Principle, Rate, Number of Year'
        read (*, *) P, R, N
        V = P * (1 + R/100) ** N
        write (*, *) 'Maturity Value (V) ', V
        stop
        end

