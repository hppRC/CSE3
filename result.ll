@i = common global i32 0, align 4
@n = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @__isoc99_scanf(i8*, ...) #1
declare dso_local i32 @printf(i8*, ...) #1

define void @initialize0() #0 {
  %1 = alloca i32, align 4
  store i32 2, i32* %1, align 4
  br label %2

2:
  %3 = load i32, i32* %1, align 4
  %4 = icmp sle i32 %3, 100
  br i1 %4, label %5, label %10

5:
  %6 = load i32, i32* %1, align 4
  br label %7

7:
  %8 = load i32, i32* %1, align 4
  %9 = add nsw i32 %8, 1
  store i32 %9, i32* %1, align 4
  br label %2

10:
  ret void
}

define void @check1(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %4 = load i32, i32* %2, align 4
  store i32 %4, i32* %3, align 4
  br label %5

5:
  %6 = load i32, i32* %3, align 4
  %7 = icmp sle i32 %6, 100
  br i1 %7, label %8, label %13

8:
  %9 = load i32, i32* %3, align 4
  %10 = load i32, i32* %3, align 4
  %11 = load i32, i32* %2, align 4
  %12 = add nsw i32 %10, %11
  store i32 %12, i32* %3, align 4
  br label %5

13:
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @initialize0()
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  %3 = load i32, i32* @n, align 4
  %4 = icmp sle i32 %3, 100
  br i1 %4, label %5, label %6

5:
  store i32 2, i32* @i, align 4
  br label %17

6:
  %7 = load i32, i32* @i, align 4
  %8 = load i32, i32* @n, align 4
  %9 = icmp sle i32 %7, %8
  br i1 %9, label %10, label %17

10:
  %11 = load i32, i32* @i, align 4
  %12 = icmp eq i32 %11, 0
  br i1 %12, label %13, label %21

13:
  %14 = load i32, i32* @i, align 4
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %14)
  %16 = load i32, i32* @i, align 4
  call void @check1(i32 %16)
  br label %18

17:
  br label %6

18:
  %19 = load i32, i32* @i, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, i32* @i, align 4
  br label %22

21:
  br label %22

22:
  ret i32 0
}
