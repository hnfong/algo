program p850;
{
	@JUDGE_ID: 20044WC PASCAL 850
}
const
	s = 'the quick brown fox jumps over the lazy dog';
var
	i,j,k,n,tc : longint;
	w : array[1..101] of string[81];
	p : array['a'..'z'] of char;
	f : boolean;
begin
	readln(tc);
	readln;
	while tc > 0 do begin
		f := false;
		dec(tc);
		n := 0;
		while not eof do begin
			inc(n);
			readln(w[n]);
			if w[n] = '' then begin
				break;
			end;
		end;
		for i := 1 to n do begin
			if not f
			and (length(w[i])=43)
			and (w[i,4]=' ')
			and (w[i,10]=' ')
			and (w[i,16]=' ')
			and (w[i,20]=' ')
			and (w[i,26]=' ')
			and (w[i,31]=' ')
			and (w[i,35]=' ')
			and (w[i,40]=' ')
			and (w[i,1]=w[i,32])
			and (w[i,2]=w[i,33])
			and (w[i,3]=w[i,34]) and (w[i,3]=w[i,29])
			and (w[i,6]=w[i,22])
			and (w[i,12]=w[i,30])
			and (w[i,13]=w[i,18]) and (w[i,13]=w[i,27]) and (w[i,13]=w[i,42])
			then begin
				for j := 1 to 43 do begin
					if w[i,j] <> ' ' then p[w[i,j]] := s[j];
				end;
				f := true;
			end;
		end;
		if f then begin
			for i := 1 to n do begin
				for j := 1 to length(w[i]) do begin
					if w[i,j] <> ' ' then write(p[w[i,j]]) else write(' ');
				end; writeln;
			end;
		end else begin
			writeln('No solution.');
			writeln;
		end;
	end;
end.
