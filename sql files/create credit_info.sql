CREATE table credit_info(
	id number,
	balance number default 500,
	constraints pk_credit primary key(id),
	constraints check_balance check(balance > 199)
);
