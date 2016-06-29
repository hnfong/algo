program p278;
{
@JUDGE_ID:  20044WC 278 PASCAL "Pattern recognition"
}
var
	i,ni : longint;
	c : char;
	m,n  : longint;
	min,max : longint;
begin
	readln(ni);
	for i := 1 to ni do begin
		readln(c,m,n);
		{ rooks: just the min of m,n }
		if c = 'r' then begin
			if n < m then writeln(n) else writeln(m);
		end;

		{ kings : (m div 2) * (n div 2) }
		if c = 'K' then writeln(( (n+1) div 2) * ( (m+1) div 2));

		{ knights : (m*n+1) div 2 with special cases }
		if c = 'k' then begin
			if (m=1) then begin writeln(n); continue; end;
			if (n=1) then begin writeln(m); continue; end;
			if (n=2) and (m=2) then begin writeln(4); continue; end;
			if (n=3) and (m=2) then begin writeln(4); continue; end;
			if (n=2) and (m=3) then begin writeln(4); continue; end;
			writeln( (m*n + 1) div 2 );
		end;

		{ queen : hypothesis:
			trivial for min(n,m) < 5
			min(n,m) for min(n,m) >= 5
		}
		if c = 'Q' then begin
			if n < m then min := n else min := m;
			if n > m then max := n else max := m;
			if min >= 5 then writeln(min);
			if min = 1 then writeln(1);
			if min = 2 then begin
				if max = 2 then writeln(1);
				if max > 2 then writeln(2);
			end;
			if min = 3 then begin
				if max = 3 then writeln(2);
				if max > 3 then writeln(3);
			end;
			if min = 4 then begin
				if max = 4 then writeln(3);
				if max > 4 then writeln(4);
			end;
		end;
	end;
end.

