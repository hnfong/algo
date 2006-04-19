program towersofhanoi;
{
	Solves the towers of hanoi problem
}
var
	x : longint;
procedure hanoi(f,t,n : longint);
begin
	if n = 1 then begin
		if abs(f-t) = 2 then begin
			writeln(f-1, ' ', 6-f-t-1);
			writeln(6-f-t-1,' ', t-1);
			exit;
		end;
		writeln(f-1, ' ' ,t-1);
		exit;
	end;

	if abs(f-t) = 2 then begin
		hanoi(f,6-f-t,n);
		hanoi(6-f-t,t,n);
		exit;
	end;
	hanoi (f, 6-f-t, n-1);
	writeln(f-1, ' ' ,t-1);
	hanoi (6-f-t, t, n-1);
end;

begin
	readln(x);
	hanoi(1,3,x);
end.
