        write (*, *) 'Base Length of Parabola and Height '
        read (*, *) bl, h
        b = bl / 2.0
        x = sqrt(4*h**2+b**2)
        L = x + b**2.0 / (2 * h) * log(2 * h + x / b)
        write (*, *) 'Length of Parabola =', L
        pause
        stop
        end
