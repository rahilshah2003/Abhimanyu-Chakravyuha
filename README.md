# Abhimanyu-Chakravyuha

# Problem statement

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 
 
Given:
- Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy a times 
- Abhmanyu can recharge himself with power b times 
- Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
- If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
-  k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle


# Algorithm

1. **Set Up:**
   - Get the starting power `p`, number of jumps `a`, and number of power-ups `b`.
   - Put the strength of the bad guys in each of the 11 rings into a list `k`.

2. **Go Through Each Ring:**
   - **Power Up:** If Abhimanyu's power `p` is lower than the bad guy's power `k[i]` and he has power-ups left (`b > 0`), he gets back to his starting power and uses up one power-up.
   - **Jump:** If `p` is still lower than `k[i]` and he can jump (`a > 0`), he skips this bad guy and moves to the next ring.
   - **Fight:** If `p` is the same or higher than `k[i]`, Abhimanyu's power drops by the bad guy's power `k[i]`. If `p` is lower than `k[i]`, Abhimanyu loses.
3. **Special Case for Circle 3 and 7:**
   - After Abhimanyu beats the bad guys in circles 3 (`k[2]`) and 7 (`k[6]`), the enemy comes back with half its starting strength.
   - See if Abhimanyu can make it through the renewed attack in the next circle. If he can't, he should use a skip if he has one; if not, Abhimanyu loses.

4. **To wrap up:**
   - If Abhimanyu makes it through all 11 circles show success; if not show failure.
