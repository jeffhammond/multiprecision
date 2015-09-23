subroutine mydotf32(n,x,jx,y,jy,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: n,jx,jy
    integer :: i
    real(kind=REAL32), intent(in) :: x(n),y(n)
    real(kind=REAL32), intent(out) :: z
    real(kind=REAL32) :: r
    if ((jx.ne.1).or.(jy.ne.1)) then
        print*,'mydotf32 supports stride 1 only'
        call abort
    endif
    r = 0.0
    do i=1,n
        r = r + x(i) * y(i)
    enddo
    z = r
    return
end subroutine mydotf32

subroutine mydotf64(n,x,jx,y,jy,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: n,jx,jy
    integer :: i
    real(kind=REAL64), intent(in) :: x(n),y(n)
    real(kind=REAL64), intent(out) :: z
    real(kind=REAL64) :: r
    if ((jx.ne.1).or.(jy.ne.1)) then
        print*,'mydotf64 supports stride 1 only'
        call abort
    endif
    r = 0.0
    do i=1,n
        r = r + x(i) * y(i)
    enddo
    z = r
    return
end subroutine mydotf64

subroutine mydotf128(n,x,jx,y,jy,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: n,jx,jy
    integer :: i
    real(kind=REAL128), intent(in) :: x(n),y(n)
    real(kind=REAL128), intent(out) :: z
    real(kind=REAL128) :: r
    if ((jx.ne.1).or.(jy.ne.1)) then
        print*,'mydotf128 supports stride 1 only'
        call abort
    endif
    r = 0.0
    do i=1,n
        r = r + x(i) * y(i)
    enddo
    z = r
    return
end subroutine mydotf128

subroutine mydotof128if64(n,x,jx,y,jy,z)
    use ISO_FORTRAN_ENV
    implicit none
    integer, intent(in) :: n,jx,jy
    integer :: i
    real(kind=REAL64), intent(in) :: x(n),y(n)
    real(kind=REAL128), intent(out) :: z
    real(kind=REAL128) :: r,tx,ty
    if ((jx.ne.1).or.(jy.ne.1)) then
        print*,'mydotf128 supports stride 1 only'
        call abort
    endif
    r = 0.0
    do i=1,n
        tx = x(i)
        ty = y(i)
        r = r + tx * ty
    enddo
    z = r
    return
end subroutine mydotof128if64
