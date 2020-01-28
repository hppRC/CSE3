; ModuleID = './samples/c/pl2e.c'
source_filename = "./samples/c/pl2e.c"
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
  br i1 %3, label %4, label %7

4:                                                ; preds = %0
  store i32 1, i32* @temp, align 4
  %5 = load i32, i32* @n, align 4
  %6 = sub nsw i32 %5, 1
  store i32 %6, i32* @n, align 4
  call void @fact()
  br label %19

7:                                                ; preds = %0
  %8 = load i32, i32* @n, align 4
  %9 = icmp sge i32 %8, 5
  br i1 %9, label %10, label %11

10:                                               ; preds = %7
  store i32 1, i32* @temp, align 4
  br label %18

11:                                               ; preds = %7
  %12 = load i32, i32* @n, align 4
  store i32 %12, i32* %1, align 4
  %13 = load i32, i32* @n, align 4
  %14 = sub nsw i32 %13, 1
  store i32 %14, i32* @n, align 4
  call void @fact()
  %15 = load i32, i32* @temp, align 4
  %16 = load i32, i32* %1, align 4
  %17 = mul nsw i32 %15, %16
  store i32 %17, i32* @temp, align 4
  br label %18

18:                                               ; preds = %11, %10
  br label %19

19:                                               ; preds = %18, %4
  ret void
}

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

declare dso_local i32 @printf(i8*, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (Red Hat 9.0.0-1.el7)"}
