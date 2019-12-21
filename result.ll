@i = common global i32 0, align 4
@s = common global i32 0, align 4
@n = common global i32 0, align 4

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 0, i32* @s, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  store i32 1, i32* @i, align 4
  br label %3

3:
  %4 = load i32, i32* @n, align 4
  %5 = load i32, i32* @i, align 4
  %6 = icmp sle i32 %4, %5
  br i1 %6, label %7, label %0

7:
  %8 = load i32, i32* @s, align 4
  %9 = load i32, i32* @i, align 4
  %10 = add nsw i32 %8, %9
  store i32 %10, i32* @s, align 4
  br label %11

11:
  %12 = load i32, i32* @i, align 4
  %13 = add nsw i32 %12, 1
  store i32 %13, i32* @i, align 4
  br label %14

14:
  %15 = load i32, i32* @s, align 4
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %15)
  ret i32 0
}
