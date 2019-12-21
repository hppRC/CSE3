@n = common global i32 0, align 4
@x = common global i32 0, align 4

define void @prime() #0 {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv i32 %2, 2
  store i32 %3, i32* %1, align 4
  br label %4

4:
  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* %1, align 4
  %8 = sdiv i32 %6, %7
  %9 = load i32, i32* %1, align 4
  %10 = mul nsw i32 %8, %9
  %11 = icmp ne i32 %5, %10
  br i1 %11, label %12, label %0

12:
  %13 = load i32, i32* %1, align 4
  %14 = sub nsw i32 %13, 1
  store i32 %14, i32* %1, align 4
  %15 = load i32, i32* %1, align 4
  %16 = icmp eq i32 %15, 1
  br i1 %16, label %17, label %0

17:
  %18 = load i32, i32* @x, align 4
  br label %19

19:
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

2:
  %3 = load i32, i32* @n, align 4
  %4 = icmp slt i32 1, %3
  br i1 %4, label %5, label %0

5:
  %6 = load i32, i32* @n, align 4
  store i32 %6, i32* @x, align 4
  %7 = load i32, i32* @n, align 4
  %8 = sub nsw i32 %7, 1
  store i32 %8, i32* @n, align 4
  ret i32 0
}
