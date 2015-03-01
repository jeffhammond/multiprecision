      subroutine mysdot(n,x,jx,y,jy,z)
        implicit none
        integer i,n,jx,jy
        real*4 x(n),y(n),z,r
        if ((jx.ne.1).or.(jy.ne.1)) then
            print*,'bad input'
        endif
        do i=1,n
            r = r + x(i) * y(i)
        enddo
        z = r
        return
      end subroutine

      subroutine myddot(n,x,jx,y,jy,z)
        implicit none
        integer i,n,jx,jy
        real*8 x(n),y(n),z,r
        if ((jx.ne.1).or.(jy.ne.1)) then
            print*,'bad input'
        endif
        do i=1,n
            r = r + x(i) * y(i)
        enddo
        z = r
        return
      end subroutine

      subroutine myqdot(n,x,jx,y,jy,z)
        implicit none
        integer i,n,jx,jy
        real*16 x(n),y(n),z,r
        if ((jx.ne.1).or.(jy.ne.1)) then
            print*,'bad input'
        endif
        do i=1,n
            r = r + x(i) * y(i)
        enddo
        z = r
        return
      end subroutine
