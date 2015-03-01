      subroutine mysdot(n,x,jx,y,jy,z)
        implicit none
        integer n,jx,jy
        real*4 x(n),y(n),z
        if ((jx.ne.1).or.(jy.ne.1)) then
            print*,'bad input'
            exit
        endif
        do i=1,n
            r = r + x(i) * y(i)
        enddo
        z = r
        return
      end subroutine
