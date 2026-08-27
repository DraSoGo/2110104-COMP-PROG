export function showTemporaryButtonStatus(button, status, idleLabel, duration = 1300, schedule = setTimeout) {
  button.textContent = status;
  schedule(() => { button.textContent = idleLabel; }, duration);
}
