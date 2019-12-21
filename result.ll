@n = common global i32 0, align 4
@x = common global i32 0, align 4

define void @prime() #0 {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv nsw i32 %2, 2
  store i32 %3, i32* %1, align 4
  br label %4

  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* %1, align 4
  %8 = sdiv nsw i32 %6, %7
  %9 = load i32, i32* %1, align 4
  %10 = mult nsw i32 %8, %9
    %12 = load i32, i32* %1, align 4
  %13 = sub nsw i32 %12, 1
  store i32 %13, i32* %1, align 4
  %14 = load i32, i32* %1, align 4
    %16 = load i32, i32* @x, align 4
 ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

  %3 = load i32, i32* @n, align 4
    %5 = load i32, i32* @n, align 4
  store i32 %5, i32* @x, align 4
  %6 = load i32, i32* @n, align 4
  %7 = sub nsw i32 %6, 1
  store i32 %7, i32* @n, align 4
 ret i32 0
}
