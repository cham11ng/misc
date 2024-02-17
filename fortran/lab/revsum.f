        write(*, *) 'Enter Number'
        read(*, *) num

        irev=0
        isum=0
 10     if(num .eq. 0) goto 20
               irem = mod(num, 10)
               irev = irev*10 + irem
               isum = isum + irem
               num = num/10
               goto 10
 20     write(*, *) 'Reversed Number = ', irev, 'Sum of Number = ',isum
        stop
        end
