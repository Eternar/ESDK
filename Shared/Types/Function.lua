---@class Function
Function = class "Function";

function Function:Constructor(handler)
    self.Delegate = handler;
end

function Function:Invoke(...)
    self.Delegate(...);
end

---Calls the delegate function with the given arguments in protected mode.
--
-- This means that any error inside the delegate function is not propagated.
function Function:InvokeSafe(onSuccess, onFail, ...)
    Function.SafeCall(self.Delegate, onSuccess, onFail, ...);
end

---@static
---Calls the function 'func' with the given arguments in protected mode.
--
-- This means that any error inside 'func' is not propagated.
function Function.SafeCall(func, onSuccess, onFail, ...)
    local status <const>, error <const> = pcall(func, ...);

    if status ~= FunctionStatus.FUNC_SUCCESS then
        if (Function.IsValid(onFail)) then
            onFail(error);
        end
    else
        if (Function.IsValid(onSuccess)) then
            onSuccess();
        end
    end
end

---@static
function Function.IsValid(func)
    return ((func ~= nil) and ((type(func) == "function") or (func.__cfx_functionReference)));
end
