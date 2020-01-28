; ModuleID = './samples/c/pl2f.c'
source_filename = "./samples/c/pl2f.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@n = common dso_local global i32 0, align 4
@temp = common dso_local global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @fact() #0 {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @n, align 4
  %3 = icmp sle i32 %2, 1
  br i1 %3, label %4, label %5

4:                                                ; preds = %0
  store i32 1, i32* @temp, align 4
  br label %27

5:                                                ; preds = %0
  br label %6

6:                                                ; preds = %25, %5
  %7 = load i32, i32* @n, align 4
  %8 = icmp sgt i32 %7, 0
  br i1 %8, label %9, label %26

9:                                                ; preds = %6
  %10 = load i32, i32* @n, align 4
  %11 = icmp sge i32 %10, 10
  br i1 %11, label %12, label %18

12:                                               ; preds = %9
  %13 = load i32, i32* @n, align 4
  store i32 %13, i32* @temp, align 4
  %14 = load i32, i32* @n, align 4
  %15 = sub nsw i32 %14, 1
  store i32 %15, i32* @n, align 4
  %16 = load i32, i32* @temp, align 4
  %17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %16)
  br label %25

18:                                               ; preds = %9
  %19 = load i32, i32* @n, align 4
  store i32 %19, i32* %1, align 4
  %20 = load i32, i32* @n, align 4
  %21 = sub nsw i32 %20, 1
  store i32 %21, i32* @n, align 4
  %22 = load i32, i32* @temp, align 4
  %23 = load i32, i32* %1, align 4
  %24 = mul nsw i32 %22, %23
  store i32 %24, i32* @temp, align 4
  br label %25

25:                                               ; preds = %18, %12
  br label %6

26:                                               ; preds = %6
  br label %27

27:                                               ; preds = %26, %4
  ret void
}

declare dso_local i32 @printf(i8*, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* @n)
  call void @fact()
  %3 = load i32, i32* @temp, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %3)
  ret i32 0
}

declare dso_local i32 @__isoc99_scanf(i8*, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (Red Hat 9.0.0-1.el7)"}
