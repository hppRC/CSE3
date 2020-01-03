@n = common global i32 0, align 4
@temp = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @__isoc99_scanf(i8*, ...) #1
declare dso_local i32 @printf(i8*, ...) #1

define void @fact(i32) #0 {
  %1 = alloca i32, align 4
  store i32 %1, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = icmp sle i32 %2, 1
  br i1 %3, label %4, label %5

4:
  store i32 1, i32* @temp, align 4
  br label %11

5:
  %6 = load i32, i32* %1, align 4
  %7 = sub nsw i32 %6, 1
  call void @fact(i32 %7)
  %8 = load i32, i32* @temp, align 4
  %9 = load i32, i32* %1, align 4
  %10 = mul nsw i32 %8, %9
  store i32 %10, i32* @temp, align 4
  br label %11

11:
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* %1)
  %3 = load i32, i32* %1, align 4
  call void @fact(i32 %3)
  %4 = load i32, i32* @temp, align 4
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %4)
  ret i32 0
}
