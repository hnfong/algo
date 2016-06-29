program p280;
{
@JUDGE_ID:  20044WC 280 PASCAL "Transitive Closure"
}
var
	i,j,k,n,nc : longint;
	a,b : longint;
	w : array[1..100,1..100] of boolean;
procedure dump;
var i,j : longint;
begin
	for i := 1 to n do begin
		for j := 1 to n do begin
			if w[i,j] then write(1) else write(0);
		end;writeln;
	end;writeln;
end;

begin
	while not eof do begin
		fillchar(w,sizeof(w),0);
		readln(n);
		if n = 0 then exit;
		{reading edges}
		while true do begin
			read(a);
			if a = 0 then begin
				readln;
				break;
			end;
			while true do begin
				read(b);
				if b = 0 then break;
				w[a,b] := true;
			end;
		end;
		for k := 1 to n do begin
			for i := 1 to n do begin
				for j := 1 to n do begin
					if w[i,k] and w[k,j] then begin
						w[i,j] := true;
					end;
				end;
			end;
		end;

		read(nc);
		for i := 1 to nc do begin
			read(a);
			k := 0;
			for j := 1 to n do begin
				if not w[a,j] then inc(k);
			end;
			write(k);
			for j := 1 to n do begin
				if not w[a,j] then write(' ', j);
			end;writeln;
		end;
		readln;
	end;
end.

