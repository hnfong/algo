program p256;
const
	hc : array[1..8] of longint = (
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000
	);
var
	i,j,k : longint;
	n : longint;
	l : longint;
	t : longint;
	r : longint;
begin
	readln(n);
	for i := 0 to hc[n div 2]-1 do begin
		for j := 0 to hc[n div 2]-1 do begin
			if (i+j) * (i+j) = i * hc[n div 2] + j then begin
				r := (i+j) * (i+j);
				t := r;
				l := 0;
				while t > 0 do begin
					t := t div 10;
					inc(l);
				end;
				if r = 0 then l := 1;
				for k := 1 to n-l do write(0);
				writeln(r);
			end;
		end;
	end;
end.
