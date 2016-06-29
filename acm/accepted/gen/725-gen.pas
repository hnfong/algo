program p725;
const
	hc : array[0..4] of longint = (1, 10, 100, 1000, 10000);
var
	i,j,k : longint;
	p : array[0..10] of byte;
	u : array[0..10] of byte;
	a,b : longint;

procedure perm(x : byte);
var
	i,j,k : longint;
begin
	if u[x] > 0 then exit;
	if p[0] >= 10 then exit;
	
	if (x = 0) then begin
		p[0] := 0;
	end else begin
		u[x] := 1;
		inc(p[0]);
		p[p[0]] := x mod 10;
	end;


	if p[0] = 10 then begin
		a := 0; b := 0;
		for i := 1 to 5 do begin
			a := a + p[i]*hc[i-1];
		end;
		for i := 6 to 10 do begin
			b := b + p[i]*hc[(i-1) mod 5];
		end;
		if (a mod b) = 0 then writeln(a div b, ' ',  a, ' ', b, ' ', a div b);
	end;

	for i := 1 to 10 do begin
		perm(i);
	end;


	if (x = 0) then begin
	end else begin
		p[p[0]] := 255;
		dec(p[0]);
		u[x] := 0;
	end;
end;

begin
	fillchar(u, sizeof(u), 0);
	perm(0);
end.
