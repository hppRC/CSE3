@n = common global i32 0, align 4
@sum = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @printf(i8*, ...) #1

define void @result3(i32, i32, i32) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %8 = load i32, i32* %5, align 4
  %9 = load i32, i32* %6, align 4
  %10 = mul nsw i32 %8, %9
  store i32 %10, i32* %7, align 4
  %11 = load i32, i32* @sum, align 4
  %12 = load i32, i32* %4, align 4
  %13 = load i32, i32* %5, align 4
  %14 = mul nsw i32 %12, %13
  %15 = add nsw i32 %11, %14
  %16 = load i32, i32* %7, align 4
  %17 = add nsw i32 %15, %16
  store i32 %17, i32* @sum, align 4
  ret void
}

define void @result0() #0 {
  %1 = load i32, i32* @sum, align 4
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %1)
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* @n, align 4
  store i32 0, i32* @sum, align 4
  br label %2

2:
  %3 = load i32, i32* @n, align 4
  %4 = icmp sgt i32 %3, 0
  br i1 %4, label %5, label %13

5:
  %6 = load i32, i32* @n, align 4
  %7 = load i32, i32* @n, align 4
  %8 = mul nsw i32 %7, 2
  %9 = load i32, i32* @n, align 4
  %10 = add nsw i32 %9, 2
  call void @result3(i32 %6, i32 %8, i32 %10)
  %11 = load i32, i32* @n, align 4
  %12 = sub nsw i32 %11, 1
  store i32 %12, i32* @n, align 4
  br label %2

13:
  call void @result0()
  ret i32 0
}
