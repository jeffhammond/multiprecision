      subroutine mysdot(n,x,jx,y,jy,z)
        implicit none
        integer n,jx,jy
        real*4 x(n),y(n),z
        if ((jx.ne.1).or.(jy.ne.1)) then
            print*,'bad input'
            exit
        endif

        return
      end subroutine
