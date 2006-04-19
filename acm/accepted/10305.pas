program p10305;
{
@JUDGE_ID:  20044WC 10305 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	n,m : longint;
	z : array[0..101,0..101] of byte;
	a,b : longint;
	emp : boolean;
	r : longint;
begin
	while true do begin
		readln(n,m);
		if (n=0) and (m=0) then break;
		fillchar(z, sizeof(z), 0);
		for i := 1 to m do begin
			readln(a,b);
			z[b,a] := 1;
		end;
		r := 0;
		while (r < n) do begin
			for i := 1 to n do begin
				if (z[i,0] = 0) then begin
					emp := true;
					for j := 1 to n do begin
						if z[i, j] > 0 then begin emp := false; break; end;
					end;
					if emp then begin
						write(i, ' ');
						z[i,0] := 1;
						for j := 1 to n do begin
							z[j,i] := 0;
						end;
						inc(r);
					end;
				end;
			end;
		end;
	end;
end.
