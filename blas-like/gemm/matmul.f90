subroutine matmulf128(row,col,inn,x,y,z,alg)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: row, col, inn, alg
    real(kind=REAL128), intent(in) :: x(row,inn),y(inn,col)
    real(kind=REAL128), intent(inout) :: z(row,col)
    integer :: i,j,k
    select case(alg)
        case(1)
            do i=1, row
              do j=1, col
                do k=1, inn
                  z(i,j) = z(i,j) + x(i,k) * y(k,j)
                enddo
              enddo
            enddo
        case default
            print*,'invalid algorithm: ',alg
    end select
    return
end subroutine matmulf128
