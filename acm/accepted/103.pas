program p103;
{
	@JUDGE_ID:  20044WC 103 PASCAL "DaP/DyP"
}
var
	f,i,j,k,n,z,t : longint;
	dp : array[0..30] of longint;
	bt : array[0..30] of longint;
	dat: array[0..31,0..10] of longint; { dat[i,0]  is the index }
function cmp(a,b : longint) : boolean;
var i : longint;
begin
	for i := 1 to n do begin
		if dat[a,i] >= dat[b,i] then begin
			cmp := false;
			exit;
		end;
	end;
	cmp := true;
	exit;
end;

begin
	while not eof do begin
		fillchar(dp,sizeof(dp),0);
		fillchar(bt,sizeof(bt),0);
		fillchar(dat,sizeof(dat),0);
		readln(z,n);
		for i := 1 to z do begin
			dat[i,0] := i;
			for j := 1 to n do begin
				read(dat[i,j]);
			end;
			readln;
		
			for j := 1 to n do begin
				for k := j downto 2 do begin
					if dat[i,k] < dat[i,k-1] then begin
						t := dat[i,k];
						dat[i,k] := dat[i,k-1];
						dat[i,k-1] := t;
					end;
				end;
			end;
		end;
		
		for i := 1 to z do begin
			for j := i downto 2 do begin
				if dat[j,1] < dat[j-1,1] then begin
					dat[31] := dat[j];
					dat[j] := dat[j-1];
					dat[j-1] := dat[31];
				end;
			end;
		end;
		
		{ dump } 
		{for i := 1 to z do begin
			for j := 0 to n do begin
				write(dat[i,j]:3);
			end;writeln;
		end;}
		

		{ DP }
		dp[z] := 1;
		bt[z] := -1;
		for i := z-1 downto 0 do begin
			dp[i] := 0;
			bt[i] := -1;
			for j := i+1 to z do begin
				if cmp(i,j) then begin
					if dp[j] > dp[i] then begin
						dp[i] := dp[j];
						bt[i] := j;
					end;
				end;
			end;
			inc(dp[i]);
		end;
		{ dump bt, dp }
		{for i := 1 to z do begin writeln('bt[',i,'] = ', bt[i], ' | dp[',i,'] = ', dp[i]); end;}
		
		writeln(dp[0]-1);
		k := bt[0];
		write(dat[k,0]);
		while k > 0 do begin
			k := bt[k];
			if k > 0 then write(' ', dat[k,0]);
		end;
		writeln;
	end;
end.
