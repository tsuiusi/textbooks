# Chapter 10: On-policy Control with Approximation
> Extending function approximation from states to actions

## Episodic semi-gradient control
Before it's learning states -> value function (U_t), now it's S_t, A_t -> U_t.
* Update target U_t 
* Update is still weighted loss x gradient (as usual)
* Episodic semi-gradient one-step SARSA

![episodicsgsarsa](src/episodicsgsarsa.png)

## Semi-gradient n-step SARSA
![enssarsa](src/enssarsa.png)
Look n steps ahead and update weights via gradient-based methods
* Again, there's an optimum somewhere between 1 and MC (same for tiling)

## Average reward: a new problem setting for continuous tasks
The quality of a policy π is defined as the average reward:
![avgr](src/avgr.png)

Ergodic: A system or process is considered ergodic if it has the same statistical properties when averaged over time as it does when averaged over the entire state space. In other words, the time average equals the space average.

# David Silver Lecture 8: Integrating Learning and Planning
Local definition of model: the agent's understanding of the environment and how states translate to other states and rewards

Recap:
* Model free RL: value function learns from environment, no model
* Model based RL: plan value function from model

> Model based doesn't mean machine-learning model, but model of the environment. Like an MDP. 

## Dyna

MDP isn't a specific thing, it's just a process where you take S, A and get R, S'
* So NNs that predict MDPs only need to take SA as an input (or even just S, then use it to predict A and R) (i thought it before he said it lets go)
* E.g taking fundamental data -> buy/sell signal
* Given S, A, what's the probability that you'll arrive in state S'
* Supervised learning problem (labeled input output)

|Parameters|Problem|
|-|-|
|Predicting reward from SA|Regression|
|Predicting probability of having state S' from SA|Density estimation|

Table lookup model is an example of non-parametric method - you just look up what the expected state would be for a given transition; learning via statistics and not gradients.
* You take observations and model the environment using it:
* It's literally just counting
![m2e](src/m2e.png)
