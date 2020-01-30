program PL4C;
forward function First(n);
forward procedure Third;
function Second(n);
begin
  Third;
  write(First(2));
  Second := n;
end;
function First(n);
begin
  First := n + 10;
end;
procedure Third;
begin
    write(3);
end;
begin
  write(Second(1));
end.