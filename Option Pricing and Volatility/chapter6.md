# Chapter 6: Option Values and Changing Market Conditions
> Don't lose money - "a trader who fails to consider thew risks associated with his position is certain to have a short an unhappy career"

### General effects of market changes
|If...|Call values will...|Put values will...|
|Price of UC increases|rise|fall|
|Price of UC decreases|fall|rise|
||||||
|Volatility rises|rise|rise|
|Volatility falls|falls|falls|
||||||
|Time passes|fall|fall|
(usually)
* Interest rates cannot be generalized, but we can look at the effect on an UC
    * High -> call, since we can appreciate via interest rates
    * Low -> UC, since carrying cost is not as great
* Opposite for puts
* In foreign currencies, buy whichever one has a higher interest rate
* Stock and foreign currency are always assumed to have stock-type settlement

### More generalizations
| Interest | If Domestic Interest Rates Rise | If Domestic Interest Rates Fall | If Foreign Interest Rates Rise | If Foreign Interest Rates Fall |
|----------|--------------------------------|--------------------------------|-------------------------------|-------------------------------|
| Calls on stock will | rise in value | fall in value | (not applicable) | (not applicable) |
| Puts on stock will | fall in value | rise in value | (not applicable) | (not applicable) |
| Calls on a foreign currency will | rise in value | fall in value | fall in value | rise in value |
| Puts on a foreign currency will | fall in value | rise in value | rise in value | fall in value |
| Calls on a futures contract will (stock type settlement) | rise in value | fall in value | (not applicable) | (not applicable) |
| Puts on a futures contract will (stock type settlement) | fall in value | rise in value | (not applicable) | (not applicable) |
| Calls on a futures contract will (futures type settlement) | remain unchanged | remain unchanged | (not applicable) | (not applicable) |
| Puts on a futures contract will (futures type settlement) | remain unchanged | remain unchanged | (not applicable) | (not applicable) |

Dividends
| If... | Call values will... | Put values will... |
|-------|---------------------|---------------------|
| The dividend is increased | fall | rise |
| The dividend is decreased | rise | fall |

## The Delta 
Again, it's the partial derivative of the predicted option price WRT the UC price.
* Always between 0 to 100%

### Rate of change
> Delta can be interpreted as the **rate of change**
* Interpret it as the rate of change relative to the UC (75 = 75% rate of change)
