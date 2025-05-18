program towersofhanoi;
{
	Solves the towers of hanoi problem
}
var
	x : longint;
procedure hanoi(f,t,n : longint);
begin
	if n = 1 then begin
		writeln('Move ', n , ' from ', chr(f+64), ' to ' , chr(t+64) );
		exit;
	end;
	hanoi (f, 6-f-t, n-1);
	writeln('Move ', n  , ' from ', chr(f+64), ' to ' , chr(t+64) );
	hanoi (6-f-t, t, n-1);
end;

begin
	readln(x);
	hanoi(1,3,x);
end.
