program x344;
{
	@JUDGE_ID:  20044WC 344 PASCAL "Siliconism"
}
const
	c : array [1..6] of char = ('i','v','x','l','c','d') ;
	p : array [1..3] of integer = (1,10,100);
var
	u : array [1..6] of longint;
	x : longint;
	i,j,k : longint;
	n : longint;
procedure dump;
var i,j,k : longint;
begin
	for i := 1 to 6 do begin write(u[i], ' '); end;writeln;
end;
begin
	readln(n);
	while (n > 0) do begin
		for i := 1 to 6 do u[i] := 0;

		for j := 1 to n do begin
			for i := 1 to 3 do begin
				x := j div p[i];
				x := x mod 10;
				if (x = 9) then begin
					u[i*2+1] := u[i*2+1] + 1;
					u[i*2-1] := u[i*2-1] + 1;
					x := x div 10;
					continue;
				end;
				u[i*2] := u[i*2] + (x div 5);
				if (x mod 5) = 4 then begin
					u[i*2] := u[i*2] + 1;
					u[i*2-1] := u[i*2-1] + 1;
				end else begin
					u[i*2-1] := u[i*2-1] + (x mod 5)
				end;
{				writeln(x);}
			end;
{			dump;}
		end;
		
		write(n:1, ':');
		for i := 1 to 4 do begin
			write(' ', u[i]:1, ' ', c[i], ',');
		end;
		write(' ', u[5]:1, ' ', c[5]);
		writeln;
		readln(n);
	end;
end.
