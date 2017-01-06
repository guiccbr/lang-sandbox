
init_amount = 958.95
num_installments = 7
month_installment = init_amount / num_installments

month_profit_rate = 0.01172

# Initial account balance
account_balance = 958.95

# Make first payment
account_balance -= month_installment;

print(account_balance)
for i in range(1, num_installments):

    # Add profit
    account_balance += account_balance*month_profit_rate

    # Pay installment
    account_balance -= month_installment

    print(account_balance)


# Parameters
init_amount = 958.95
num_installments = 7
month_installment = init_amount / num_installments
month_profit_rate = 0.01172

# Initial account balance
account_balance = init_amount

# Make first payment
account_balance -= month_installment;

print(account_balance)
for i in range(1, num_installments):

    # Add profit
    account_balance += account_balance*month_profit_rate

    # Pay installment
    account_balance -= month_installment

    print(account_balance)

