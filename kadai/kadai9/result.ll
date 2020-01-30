@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare dso_local i32 @printf(i8*, ...) #1

define i32 @Second1(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  call void @Third0()
  %4 = call i32 @First1(i32 2)
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %4)
  %6 = load i32, i32* %3, align 4
  store i32 %6, i32* %2, align 4
  %7 = load i32, i32* %2, align 4
  ret i32 %7
}

define i32 @First1(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = add nsw i32 %4, 10
  store i32 %5, i32* %2, align 4
  %6 = load i32, i32* %2, align 4
  ret i32 %6
}

define void @Third0() #0 {
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 3)
  ret void
}

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 @Second1(i32 1)
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %2)
  ret i32 0
}
