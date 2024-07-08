# Chapter 3: Introduction to Theoretical Pricing Models 
> Correctly predicting speed *and* direction is usually beyond most traders' capabilities
> Quantitative trading is more suited to highly complex markets with more hidden trends and patterns, more dimensions to play with
> Data -> model -> prediction

### Quantifying strategies with numbers rather than "probably"
* Direction of market heavily influences trading strategy
* Normal investors might buy one thing, wait until it hits the target price, then sell
* Option traders have more to deal with; options constantly change and opportunities open and close very frequently
* Underlying market trader is interested exclusively in how the market moves, option traders also watch how people move - how fast the market moves 
* Speed is essential - you get the speed wrong, you die

At minimum a trader must consider:
1. Price of underlying contract
2. Exercise price
3. The amount of remaining time
4. The direction he expects the underlying market to move
5. The expected movement speed

Ideally, you can quantify everything, use a formula, and derive a value for the option (like arbitrage betting). The goal of option evaluation is to **analyze an option based on the terms of the option contract, as well as current market conditions and future expectations.**

## Expected return and theoretical value
Expected return is exactly what you'd expect

Theoretical value: the price you'd expect to pay to break even. 
> The most common considerations are the expected return and value of proposition, but there are other considerations: **carrying cost** 

e.g roulette. 
* You give the casino 0.95, and if you lose, you give it to them immediately; if you win, and they will send you the $36 in 2 months.
* The 0.95 you took out could've been compounding in the bank (book give 12%, insane) so you'd lose 0.02 on that. 
* So the theoretical value of the bet is the E[x] of 0.95 - 0.02 carrying cost = 0.93

Exchanges are basically casinos.

## Notes on models
> In each case, the model is constructed to help us better understand the world in which we live. However, it is unwise, and sometimes dangerous, to assume that the model and the real world which it represents are indentical in every way.

* Knowing about them is important but by no means do they ensure success
* Can't rely on one thing
* "A new option trader is like someone entering a dark room, and the models a dim candle. He can pick out the general layout, but not the fine details. What he sees may also be distorted by the candle."

Have full awareness of the limitations; a lot of successful option traders use them, so just be smart about it.

## A simple approach
Starting with an example:
* Suppose an underlying contract (hereonafter UC) is trading at 100 and on the expiration, it can be one of the following prices {80, 90, 100, 110, 120}. Uniform distribution.
    * Expected value is 0
* Now suppose we take a long position in a 100 call
    * The call is worthless at anything <= 100
    * The expected value is (0.2 * 0)\*3 + (0.2 * 10) + (0.2 * 20) = 6
    * Call can never have negative value

Now add the factors of carrying costs and returns at expiration:
* Removing the 2% carrying cost (interest) of the 6 expected return, the theoretical value is 5.88
* etc, etc, keep tweaking ratios and distribution

Now include dividends:
* If the dividend is paid during the holding period, it'll affect the expected return. 
* The buyer receives the dividends
* Subtract dividend from carrying cost

Arbitrage-free markets: when no profits can be made by either buying/selling a contract, all credits and debits (including expected return) must exactly cancel out
* Forward price (price of contract at the end of the holding period) is the current price + expected return to offset debits/credits\
* e.g holding costs are 4 for a 100 stock, forward must be 104; dividend 1, forward 103. 
* Calculation of forward is dependent on market conditions and the characteristics of the contract.
    * Stocks: price, holding period duration, interest rates, dividends
    * Futures: the option purchase price

Using this assumption, we can find the expected return for any underlying contract. In the case of futures, it's zero.

Basically it's a) making some assumptions to simplify the decision making process, b) quantifying the information provided, and c) using real-world data to predict what will happen and act accordingly

### Summarized steps of developing a model
1. Propose a series of possible prices at expiration for the underlying contract
2. Assign a probability to each price
3. Maintain an arbitrage-free underlying market
4. From the prices adn probabilities in steps 1, 2, and 3, calculate the expected return for the option
5. From the expected return, deduct the carrying cost
> From this we get a theoretical value from which we can begin to trade. (make decisions at, like if it's over/underpriced, basically an analysis of the underlying contract/asset)

Evaluation used be slow, now we have computers. 

The **Black-Scholes Model** (a super popular one because of its simplicity and observable processes) was and is one of the most widely used models.
* Differentiation is between data (amount, type, preprocessing, how it's represented. Think LLMs), additional mods, execution speed, risk management, and the strategies derived from the data
* Futures and forex versions are known as Black model and Garman-Kohlhagen model respectively

### Black-Scholes Model
Minimum 5 characteristics about the option and its underlying model:
1. Exercise price
2. Amount of time remaining to expiration
3. Current price of underlying contract
4. Risk-free interest rate over the life of the option
5. Volatility of the underlying contract

They also incorporated the idea of a *riskless hedge*, which is that for every option there is a theoretically equivalent position in the underlying contract that for small price changes in the underlying contract the option position will gain/lose value at exactly the same rate (for small price changes).
* To take advantage of a theoretically mispriced option, hedges are established - opposing market positions to offset the option position
* The correct proportion of underlying contracts to establish this riskless hedge is the *hedge ratio*

Example: 
* If the price is 100 and there's 0.25 chance it goes to 120, the probability might drop down to 0.1 if the price drops to 80 (live adjustment). 
* If you establish a riskless hedge, then by adjusting the hedge as market conditions change, you account for these events
* Option is the substitute for the position {long: call, short: put}
* If a call can be purchased/sold for less/more than its theoretical value, it will in the long run be more profitable to long/short the position by buying/selling calls rather than the underlying contract
* Same thing for puts, but more rather than less

## Definitions and elaborations
### Exercise price
well duh. can't be changed. value specified by the contract.

### Time to expiration
* Entered into BS model as an annualized number - percentage of a year
* Usually incorporated into the model, just input days
* Trading days inputted only for volatility calcs but interest compounds on holidays too yknow
* Just parameters to adjust for this

### Price of underlying
* Bid price, asked price 
* "the correct use of an option's theoretical value requires us to hedge the option position with an opposing trade in the underlying contract"
* Usually people use the last trade price as a basis, not precise, **experienced traders will rarely enter an option market without knowing the exact bid and offer in the underlying market**

### Interest rates
* Effect depends on the type of settlement
    * Stock type -> increasing interest rate decreases value of option (since getting the issue itself would be better)
    * Also increases forward price -> value of calls, decreses puts
* Rates might also be different due to currency
* Significance varies
* Value used depends on the issue, yield of bonds/government securities are generally used for benchmarking (60 day option -> 60 day bond)

### Dividends
* Only a factor in stocks that pay dividends, can be omitted
* Assume they use the same policy
* Ex-dividend dates and that time period is very unpredictable
* So they kinda just ignore it

### Volatility
* see next chapter
