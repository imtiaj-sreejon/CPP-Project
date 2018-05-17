CREATE table smartcard_info(
	id number,
	balance number default 500,
	constraints pk_credit primary key(id),
	constraints fk_card_student foreign key(student_id) references student,
	constraints uni_std_id unique(student_id),
	constraints check_balance check(balance > 199)
);
