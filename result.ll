@i = common global i32 0, align 4
@j = common global i32 0, align 4
@n = common global i32 0, align 4
@a = common global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @__isoc99_scanf(i8*, ...) #1
declare dso_local i32 @printf(i8*, ...) #1

define void @initialize1(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  store i32 1, i32* %3, align 4
  br label %4

4:
  %5 = load i32, i32* %3, align 4
  %6 = load i32, i32* %2, align 4
  %7 = icmp sle i32 %5, %6
  br i1 %7, label %8, label %16

8:
  %9 = load i32, i32* %3, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [100 x i32], [100 x i32]* %10, i64 0, i64 @a
  %12 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* %11)
  br label %13

13:
  %14 = load i32, i32* %3, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %3, align 4
  br label %4

16:
  ret void
}

define void @swap1(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %4 = load i32, i32* %2, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [100 x i32], [100 x i32]* %5, i64 0, i64 @a
  store i32 %6, i32* %3, align 4
  %7 = load i32, i32* %2, align 4
  %8 = load i32, i32* %2, align 4
  %9 = add nsw i32 %8, 1
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [100 x i32], [100 x i32]* %10, i64 0, i64 @a
  %12 = sext i32 %11 to i64
  %13 = getelementptr inbounds [100 x i32], [100 x i32]* %12, i64 0, i64 @a
  %14 = load i32, i32* %2, align 4
  %15 = add nsw i32 %14, 1
  %16 = load i32, i32* %3, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [100 x i32], [100 x i32]* %17, i64 0, i64 @a
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  %3 = load i32, i32* @n, align 4
  %4 = icmp sle i32 %3, 100
  br i1 %4, label %5, label %8

5:
  %6 = load i32, i32* @n, align 4
  call void @initialize1(i32 %6)
  %7 = load i32, i32* @n, align 4
  store i32 %7, i32* @i, align 4
  br label %12

8:
  %9 = load i32, i32* @i, align 4
  %10 = icmp sle i32 1, %9
  br i1 %10, label %11, label %27

11:
  store i32 1, i32* @j, align 4
  br label %27

12:
  %13 = load i32, i32* @j, align 4
  %14 = load i32, i32* @i, align 4
  %15 = icmp slt i32 %13, %14
  br i1 %15, label %16, label %30

16:
  %17 = load i32, i32* @j, align 4
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [100 x i32], [100 x i32]* %18, i64 0, i64 @a
  %20 = load i32, i32* @j, align 4
  %21 = add nsw i32 %20, 1
  %22 = sext i32 %21 to i64
  %23 = getelementptr inbounds [100 x i32], [100 x i32]* %22, i64 0, i64 @a
  %24 = icmp sgt i32 %19, %23
  br i1 %24, label %25, label %12

25:
  %26 = load i32, i32* @j, align 4
  call void @swap1(i32 %26)
  br label %37

27:
  %28 = load i32, i32* @j, align 4
  %29 = add nsw i32 %28, 1
  store i32 %29, i32* @j, align 4
  br label %12

30:
  %31 = load i32, i32* @i, align 4
  %32 = sext i32 %31 to i64
  %33 = getelementptr inbounds [100 x i32], [100 x i32]* %32, i64 0, i64 @a
  %34 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %33)
  %35 = load i32, i32* @i, align 4
  %36 = sub nsw i32 %35, 1
  store i32 %36, i32* @i, align 4
  br label %38

37:
  br label %38

38:
  ret i32 0
}
