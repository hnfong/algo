function a(n : integer) : integer;
var
  i , acc : integer;
begin
  acc:=1;
  for i:=2 to n do
  begin
    acc:=acc * i;
    {#}
  end;
  a:=acc
end;

function b(n : integer): int64;
var
  acc : int64;
  i : integer;
begin
  acc:=1;
  for i:=2 to n do
  begin
    acc:=acc * i;
    {#}
  end;
  b:= acc;
end;

function c(n : integer) : int64;
begin
	c := (b(n) + 32768) mod 65536 - 32768;
end;

var i : integer;
begin
	for i := 1 to 30 do begin
		writeln(i:3,a(i):30,b(i):30,c(i):30);
	end;
end.
