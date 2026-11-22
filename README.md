*This project has been created as part of the 42 curriculum by lensauva.*

## flag <->
| `type value` | purpose | 
|--------------|---------|
| | overwrited by flag <.> |
| | overwrite the flag <0> |
| | the sign count for len(value) |
| | the space of flag < > count for len(value) |
| | the plus of flag <+> count for len(value) |
| | the '0x' of flag <#> count for len(value) |
| | the '0x' %p count for len(value) |
| c s d i u x X p | if number of flag was upper than len(value) add ' ' for difference after value. |
| | if number of flag was lowpper than len(value) don't take care of purpose of flag. |


## flag <0>
| `type value` | purpose | 
|--------------|---------|
| | overwrited by flag <-> |
| | overwrited by flag <.> |
| | the sign count for len(value) |
| | the space of flag < > count for len(value) |
| | the plus of flag <+> count for len(value) |
| | the '0x' of flag <#> count for len(value) |
| | the '0x' %p count for len(value) |
| d i u x X | if number of flag was upper than len(value) add '0' for difference. |
| | if number of flag was lowpper than len(value) don't take care of purpose of flag. |
| p | if number of flag was upper than len(value) add '0' after '0x' for difference. |
| | if number of flag was lowpper than len(value) don't take care of purpose of flag. |
| c s | do nothing |


## flag <.>
| `type value` | purpose | 
|--------------|---------|
| | overwrite the flag <0> |
| | overwrite the flag <-> |
| | the sign don't count for len(value) |
| | the space of flag < > don't count for len(value) |
| | the plus of flag <+> dont't count for len(value) |
| | the '0x' of flag <#> don't count for len(value) |
| | the '0x' of %p don't count for len(value) |
| d i u x X p | if number of flag was upper than len(value) add '0' for difference. |
| | if number of flag was lowpper than len(value) don't take care of purpose of flag. |
| s | print maximun of number after <.> of string |
| c | do nothing |


## flag <#>
| `type value` | purpose | 
|--------------|---------|
| | if value is 0 not print '0x' |
| c s d i u p | do nothing |
| x | add '0x' at the beginning of value |
| X | add '0X' at the beginning of value |


## flag < >
| `type value` | purpose | 
|--------------|---------|
| | overwrited by flag <+> |
| c s u x X | do nothing |
| p i d | if value is positive add a space before the value |


## flag <+>
| `type value` | purpose | 
|--------------|---------|
| | overwrite the flag < > |
| c s u x X | do nothing |
| p i d | if value is positive add a plus before the value |

