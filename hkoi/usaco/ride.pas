{
PROG: ride
ID: sydneyf1
}
program ride;
var
	s1,s2 : string;
	i, a,b : longint;
begin
	assign(input,'ride.in');
	reset(input);
	assign(output,'ride.out');
	rewrite(output);
	readln(s1);
	readln(s2);
	a := 1;
	b := 1;
	for i := 1 to length(s1) do begin
		a := a * (ord(s1[i])-64);
	end;
	for i := 1 to length(s2) do begin
		b := b * (ord(s2[i])-64);
	end;
	if (a mod 47) = (b mod 47) then writeln('GO') else writeln('STAY');
	close(output);
	close(input);
end.
