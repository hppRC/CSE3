@n = common global i32 0, align 4
@temp = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @__isoc99_scanf(i8*, ...) #1
declare dso_local i32 @printf(i8*, ...) #1

define void @fact(i32, i32) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %3, i32* %4, align 4
  store i32 %1, i32* %4, align 4
  %5 = load i32, i32* %2, align 4
  %6 = icmp sle i32 %5, 1
  br i1 %6, label %7, label %8

7:
  store i32 1, i32* @temp, align 4
  br label %15

8:
  %9 = load i32, i32* %2, align 4
  %10 = sub nsw i32 %9, 1
  %11 = load i32, i32* %3, align 4
  call void @fact(i32 %10, i32 %11)
  %12 = load i32, i32* @temp, align 4
  %13 = load i32, i32* %2, align 4
  %14 = mul nsw i32 %12, %13
  store i32 %14, i32* @temp, align 4
  br label %15

15:
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  %3 = load i32, i32* @n, align 4
  call void @fact(i32 %3, i32 1)
  %4 = load i32, i32* @temp, align 4
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %4)
  ret i32 0
}
