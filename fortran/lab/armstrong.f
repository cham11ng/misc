        write(*, *) 'Enter Number'
        read(*, *) num

        itemp=num
        isum=0
 10     if(num .eq. 0) goto 20
               irem = mod(num, 10)
               isum = isum + irem**3
               num = num/10
               goto 10
 20     if(isum .eq. itemp) goto 5
               write(*, *) 'NOT ArmStrong Number'
        stop
 5      write(*, *) 'ArmStrong Number'
        stop
        end
