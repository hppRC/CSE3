@n = common global i32 0, align 4
@x = common global i32 0, align 4
@i = common global i32 0, align 4

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
  br label %15

15:
  %16 = load i32, i32* %1, align 4
  %17 = icmp eq i32 %16, 1
  br i1 %17, label %18, label %0

18:
  %19 = load i32, i32* @x, align 4
  %20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %19)
  br label %21

21:
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = alloca i32, align 4
  %3 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  store i32 2, i32* @i, align 4
  br label %4

4:
  %5 = load i32, i32* @n, align 4
  %6 = load i32, i32* @i, align 4
  %7 = icmp sle i32 %5, %6
  br i1 %7, label %8, label %0

8:
  %9 = load i32, i32* @i, align 4
  store i32 %9, i32* @x, align 4
  call void @prime()
  br label %10

10:
  %11 = load i32, i32* @i, align 4
  %12 = add nsw i32 %11, 1
  store i32 %12, i32* @i, align 4
  br label %13

13:
  ret i32 0
}
